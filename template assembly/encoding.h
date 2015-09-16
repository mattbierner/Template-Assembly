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

constexpr unsigned get_mode_for_disp(unsigned disp, bool needsDisp) {
    if (disp == 0 && !needsDisp)
        return 0b00;
    else if (disp > 0xff)
        return 0b10;
    else
        return 0b01;
};

template <size_t disp, bool needsDisp>
struct get_disp : IntToBytes< (disp > 0xff) ? 4 : 1, disp> {};

template <>
struct get_disp<0, false> {
    using type = ByteString<>;
};

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
using make_modrm = typename IntToBytes<1, (mode << 6) + (reg << 3) + rm>::type;

/**
    Construct a sib byte.
*/
template <unsigned scale, unsigned index, unsigned base>
using make_sib = typename IntToBytes<1, (scale << 6) + (index << 3) + base>::type;

/**
    Construct a rex byte.
*/
template <bool w, bool r, bool b, bool x>
using rex = typename IntToBytes<1, (0b0100 << 4) | (w << 3) | (r << 2) | (b << 1) | x>::type;


/**
    Build the modrm section of an instruction from the operands.
*/
template <typename... operands>
struct modrm;

template <size_t s, size_t i>
struct modrm<GeneralPurposeRegister<s, i>> {
    using type = make_modrm<0b11, 0b01, GeneralPurposeRegister<s, i>::index>;
};

template <size_t s, size_t i, typename T, T x>
struct modrm<GeneralPurposeRegister<s, i>, Immediate<T, x>> {
    using type = make_modrm<0b11, 0, GeneralPurposeRegister<s, i>::index>;
};

template <size_t s, size_t i, size_t s2, size_t i2>
struct modrm<GeneralPurposeRegister<s, i>, GeneralPurposeRegister<s2, i2>> {
    using type = make_modrm<0b11,
        GeneralPurposeRegister<s2, i2>::index,
        GeneralPurposeRegister<s, i>::index>;
};

/// Memory displacement only
template <size_t s, size_t i, size_t size, size_t mult, size_t disp>
struct modrm<GeneralPurposeRegister<s, i>, Memory<size, None, None, mult, disp>> {
    using type = bytes_join<
        make_modrm<0, GeneralPurposeRegister<s, i>::index, 4>,
        ByteString<'\x25'>,
        typename IntToBytes<4, disp>::type>;
};

/// Memory reg1 only
template <size_t s, size_t i, size_t size, typename reg, size_t mult, size_t disp>
struct modrm<GeneralPurposeRegister<s, i>, Memory<size, reg, None, mult, disp>> {
    template <size_t reg1Size, size_t reg1Index>
    struct impl {
        using type = bytes_join<
            make_modrm<Details::get_mode_for_disp(disp, false), GeneralPurposeRegister<s, i>::index, reg::index>,
            typename Details::get_disp<disp, false>::type>;
    };
    
    template <size_t reg1Size> // esp
    struct impl<reg1Size, 4> {
        using type = bytes_join<
            make_modrm<Details::get_mode_for_disp(disp, false), GeneralPurposeRegister<s, i>::index, reg::index>,
            make_sib<0, 4, 4>,
            typename Details::get_disp<disp, false>::type>;
    };
    
    using type = typename impl<reg::size, reg::index>::type;
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
    return GeneralPurposeRegister<s, i>::index;
};

/**
*/
template <size_t s, size_t i>
constexpr bool get_rex_b(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index;
};