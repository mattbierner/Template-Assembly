#pragma once

#include <tasm/private/byte_string.h>
#include <tasm/private/immediate.h>
#include <tasm/private/memory.h>
#include <tasm/private/register.h>
#include <tasm/private/utility.h>

namespace tasm { namespace instruction {

constexpr unsigned get_index(tasm::details::None) {
    return 0;
}

template <size_t s, size_t i>
constexpr unsigned get_index(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index;
}

constexpr unsigned get_mode_for_disp(Displacement disp, bool needsDisp) {
  return
    disp == 0 && !needsDisp
        ?0b00
    :disp > 0xff || disp < -0xff
        ?0b10
    :0b01;
}

template <Displacement disp, bool needsDisp>
struct get_disp : byte_string::IntToBytes<(disp > 0xff || disp < -0xff) ? 4 : 1, disp> {};

template <>
struct get_disp<0, false> {
    using type = byte_string::ByteString<>;
};

constexpr unsigned to_sib_scale(unsigned x) {
    return
        x == 2
            ?0b01
        :x == 4
            ?0b10
        :x == 8
            ?0b11
        :0b00;
}

/**
    Instruction prefix.
*/
template <char... codes>
using Prefix = byte_string::ByteString<codes...>;

/**
    Instruction opcode byte.
*/
template <char... codes>
using Opcode = byte_string::ByteString<codes...>;

/**
    Construct a modm byte.
*/
template <unsigned mode, unsigned reg, unsigned rm>
using make_modrm = typename byte_string::IntToBytes<1, ((mode & 0b11) << 6) + ((reg & 0b111) << 3) + (rm & 0b111)>::type;

/**
    Construct a sib byte.
*/
template <unsigned scale, unsigned index, unsigned base>
using make_sib = typename byte_string::IntToBytes<1, ((scale & 0b11) << 6) + ((index & 0b111) << 3) + (base & 0b111)>::type;

/**
    Construct a rex byte.
*/
template <bool w, bool r, bool x, bool b>
using make_rex = typename byte_string::IntToBytes<1, (0b0100 << 4) + (w << 3) + (r << 2) + (x << 1) + b>::type;

/**
    Build the modrm section of an instruction from the operands.
*/
template <int code, typename... operands>
struct modrm;

/// Register only
template <int code, size_t s, size_t i>
struct modrm<code, GeneralPurposeRegister<s, i>> {
    using type = make_modrm<0b11, code, GeneralPurposeRegister<s, i>::index>;
};

/// Memory base only
template <int code, size_t size, typename reg1, size_t mult, Displacement disp>
struct modrm<code, Memory<size, reg1, tasm::details::None, mult, disp>> {
    template <size_t reg1Index, typename _>
    struct impl {
        using type = byte_string::bytes_join<
            make_modrm<get_mode_for_disp(disp, (reg1::index == 5)), code, reg1::index>,
            typename get_disp<disp, (reg1::index == 5)>::type>;
    };

    // reg1 == esp special case.
    template <typename _>
    struct impl<4, _> {
        using type = byte_string::bytes_join<
            make_modrm<get_mode_for_disp(disp, true), code, reg1::index>,
            make_sib<0, 4, 4>,
            typename get_disp<disp, true>::type>;
    };

    using type = typename impl<reg1::index, void>::type;
};


/// Register - Immediate
template <int code, size_t s, size_t i, typename T, T x>
struct modrm<code, GeneralPurposeRegister<s, i>, Immediate<T, x>> {
    using type = make_modrm<0b11, code, GeneralPurposeRegister<s, i>::index>;
};

/// Register - Registers
template <size_t s1, size_t i1, size_t s2, size_t i2>
struct modrm<-1, GeneralPurposeRegister<s1, i1>, GeneralPurposeRegister<s2, i2>> {
    using type = make_modrm<0b11,
        GeneralPurposeRegister<s2, i2>::index,
        GeneralPurposeRegister<s1, i1>::index>;
};

/// Register - Memory displacement only
template <size_t s, size_t i, size_t size, size_t mult, Displacement disp>
struct modrm<-1, GeneralPurposeRegister<s, i>, Memory<size, tasm::details::None, tasm::details::None, mult, disp>> {
    using type = byte_string::bytes_join<
        make_modrm<0, GeneralPurposeRegister<s, i>::index, 4>,
        byte_string::ByteString<'\x25'>,
        typename byte_string::IntToBytes<4, disp>::type>;
};

/// Register - Memory reg1 only
template <size_t s, size_t i, size_t size, typename reg, size_t mult, Displacement disp>
struct modrm<-1, GeneralPurposeRegister<s, i>, Memory<size, reg, tasm::details::None, mult, disp>> {
    template <size_t reg1Size, size_t reg1Index>
    struct impl {
        using type = byte_string::bytes_join<
            make_modrm<
                get_mode_for_disp(disp, (reg1Index == 5)),
                GeneralPurposeRegister<s, i>::index,
                reg::index>,
            typename get_disp<disp, (reg1Index == 5)>::type>;
    };

    /// reg1 == esp special case
    template <size_t reg1Size>
    struct impl<reg1Size, 4> {
        using type = byte_string::bytes_join<
            make_modrm<
                get_mode_for_disp(disp, true),
                GeneralPurposeRegister<s, i>::index,
                reg::index>,
            make_sib<0, 4, 4>,
            typename get_disp<disp, true>::type>;
    };

    using type = typename impl<reg::size, reg::index>::type;
};

/// Register - Memory reg1 and reg2
template <size_t s, size_t i, size_t size, typename reg, typename reg2, size_t mult, Displacement disp>
struct modrm<-1, GeneralPurposeRegister<s, i>, Memory<size, reg, reg2, mult, disp>> {

    template <size_t reg2Index, typename _>
    struct impl {
        using type = byte_string::bytes_join<
            make_modrm<get_mode_for_disp(disp, (reg2Index == 5)), GeneralPurposeRegister<s, i>::index, 4>,
            make_sib<to_sib_scale(mult), reg2::index, reg::index>,
            typename get_disp<disp, (reg2Index == 5)>::type>;
    };

    /// reg1 == esp special case
    template <typename _>
    struct impl<4, _> {
        using type = byte_string::bytes_join<
            make_modrm<get_mode_for_disp(disp, true), GeneralPurposeRegister<s, i>::index, 4>,
            make_sib<to_sib_scale(mult), reg2::index, reg::index>,
            typename get_disp<disp, true>::type>;
    };

    using type = typename impl<reg::index, void>::type;
};

/**
    Get the r bit of the REX byte.
*/
template <size_t s, size_t i>
constexpr bool get_rex_r(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index > 7;
}

/**
    Get the b bit of the REX byte.
*/
template <size_t s, size_t i>
constexpr bool get_rex_b(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index > 7;
}

}} // tasm::instruction
