#pragma once

#include "byte_string.h"
#include "immediate.h"
#include "memory.h"
#include "register.h"

namespace Details {

constexpr unsigned get_index(None) {
    return 0;
}

template <size_t s, size_t i>
constexpr unsigned get_index(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index;
}

constexpr unsigned get_mode_for_disp(Displacement disp, bool needsDisp) {
    if (disp == 0 && !needsDisp)
        return 0b00;
    else if (disp > 0xff || disp < -0xff)
        return 0b10;
    else
        return 0b01;
};

template <Displacement disp, bool needsDisp>
struct get_disp : IntToBytes< (disp > 0xff) ? 4 : 1, disp> {};

template <>
struct get_disp<0, false> {
    using type = ByteString<>;
};

constexpr unsigned to_sib_scale(unsigned x) {
    switch (x) {
    case 1:  return 0b00;
    case 2:  return 0b01;
    case 4:  return 0b10;
    case 8:  return 0b11;
    default: return 0b00;
    }
}

} // Details

/**
    Instruction prefix.
*/
template <char... codes>
using Prefix = ByteString<codes...>;

/**
    Instruction opcode byte.
*/
template <char... codes>
using Opcode = ByteString<codes...>;

/**
    Construct a modm byte.
*/
template <unsigned mode, unsigned reg, unsigned rm>
using make_modrm = typename IntToBytes<1, ((mode & 0b11) << 6) + ((reg & 0b111) << 3) + (rm & 0b111)>::type;

/**
    Construct a sib byte.
*/
template <unsigned scale, unsigned index, unsigned base>
using make_sib = typename IntToBytes<1, ((scale & 0b11) << 6) + ((index & 0b111) << 3) + (base & 0b111)>::type;

/**
    Construct a rex byte.
*/
template <bool w, bool r, bool x, bool b>
using make_rex = typename IntToBytes<1, (0b0100 << 4) + (w << 3) + (r << 2) + (x << 1) + b>::type;

/**
    Build the modrm section of an instruction from the operands.
*/
template <int code, typename... operands>
struct modrm;

// Register only
template <size_t code, size_t s, size_t i>
struct modrm<code, GeneralPurposeRegister<s, i>> {
    using type = make_modrm<0b11, code, GeneralPurposeRegister<s, i>::index>;
};

/// Memory only
template <size_t code, size_t size, typename reg1, size_t mult, Displacement disp>
struct modrm<code, Memory<size, reg1, None, mult, disp>> {
    using type = bytes_join<
        make_modrm<Details::get_mode_for_disp(disp, true), code, reg1::index>,
        make_sib<0, 4, 4>,
        typename Details::get_disp<disp, true>::type>;
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
struct modrm<-1, GeneralPurposeRegister<s, i>, Memory<size, None, None, mult, disp>> {
    using type = bytes_join<
        make_modrm<0, GeneralPurposeRegister<s, i>::index, 4>,
        ByteString<'\x25'>,
        typename IntToBytes<4, disp>::type>;
};

/// Register - Memory reg1 only
template <size_t s, size_t i, size_t size, typename reg, size_t mult, Displacement disp>
struct modrm<-1, GeneralPurposeRegister<s, i>, Memory<size, reg, None, mult, disp>> {
    template <size_t reg1Size, size_t reg1Index>
    struct impl {
        using type = bytes_join<
            make_modrm<Details::get_mode_for_disp(disp, (reg1Index == 5)), GeneralPurposeRegister<s, i>::index, reg::index>,
            typename Details::get_disp<disp, (reg1Index == 5)>::type>;
    };
    
    /// reg1 == esp special case
    template <size_t reg1Size>
    struct impl<reg1Size, 4> {
        using type = bytes_join<
            make_modrm<Details::get_mode_for_disp(disp, true), GeneralPurposeRegister<s, i>::index, 4>,
            make_sib<0, 4, 4>,
            typename Details::get_disp<disp, true>::type>;
    };
    
    using type = typename impl<reg::size, reg::index>::type;
};

/// Register - Memory reg1 and reg2
template <size_t s, size_t i, size_t size, typename reg, typename reg2, size_t mult, Displacement disp>
struct modrm<-1, GeneralPurposeRegister<s, i>, Memory<size, reg, reg2, mult, disp>> {

    template <size_t reg2Index, typename _>
    struct impl {
        using type = bytes_join<
            make_modrm<Details::get_mode_for_disp(disp, (reg2Index == 5)), GeneralPurposeRegister<s, i>::index, 4>,
            make_sib<Details::to_sib_scale(mult), reg2::index, reg::index>,
            typename Details::get_disp<disp, (reg2Index == 5)>::type>;
    };
    
    /// reg1 == esp special case
    template <typename _>
    struct impl<4, _> {
        using type = bytes_join<
            make_modrm<Details::get_mode_for_disp(disp, true), GeneralPurposeRegister<s, i>::index, 4>,
            make_sib<Details::to_sib_scale(mult), reg2::index, reg::index>,
            typename Details::get_disp<disp, true>::type>;
    };
    
    using type = typename impl<reg::index, void>::type;
};

/**
*/
template <size_t s, size_t i>
constexpr unsigned get_reg(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index;
};

/**
*/
template <size_t s, size_t i>
constexpr bool get_rex_r(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index > 7;
};

/**
*/
template <size_t s, size_t i>
constexpr bool get_rex_b(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index > 7;
};