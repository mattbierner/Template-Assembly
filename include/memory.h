#pragma once

#include "immediate.h"
#include "register.h"

namespace tasm {

using Displacement = int32_t;

/**
    Asm memory address.
    
    Suppored syntaxes:
    
        _[eax]    [eax]
        _[4_b]    [4]
 
        _[eax + 4_b]        [eax + 4]
 
        _[eax + ecx]         [eax + ecx]
        _[eax + 4_b + ecx]   [eax + 4 + ecx]
        _[eax + ecx * 2_b]        [eax + ecx * 2]
        _[eax + 4_b + ecx * 2_b]     [eax + 4 + ecx * 2]
*/
template <
    size_t size,
    typename reg1,
    typename reg2,
    size_t scale,
    Displacement disp>
struct Memory {
    static_assert(scale == 0 || scale == 1 || scale == 2 || scale == 4 || scale == 8, "Invalid scale.");
};

/**
    `_` - Sugar to construct initial memory addresses from registers or displacements.
*/
constexpr struct {
    /**
        Create a memory address from a register.
    */
    template <size_t size, size_t index>
    constexpr auto operator[](GeneralPurposeRegister<size, index> r) const {
        return Memory<size, decltype(r), None, 0, 0>{};
    }

    /**
        Displayment only address.
    */
    template <Displacement size, typename T, T x>
    constexpr auto operator[](Immediate<T, x>) const {
        static_assert(x < 0xffff, "Displacement too large");
        return Memory<size, None, None, 0, x>{};
    }
    
    /**
        Identity function to support syntax like `_[esp + 4_b]`
    */
    template <size_t size, typename reg, typename reg2, size_t mult, Displacement disp>
    constexpr auto operator[](Memory<size, reg, reg2, mult, disp> mem) const {
        return mem;
    }
} _ { };

/**
    Add displayment to memory.
*/
template <size_t size, typename reg1, typename reg2, size_t mult, Displacement disp, typename T, T x>
constexpr auto operator+(Memory<size, reg1, reg2, mult, disp>, Immediate<T, x>) {
    return Memory<size, reg1, reg2, mult, disp + x>{};
}
template <size_t size, typename reg1, typename reg2, size_t mult, Displacement disp, typename T, T x>
constexpr auto operator+(Immediate<T, x> d, Memory<size, reg1, reg2, mult, disp> mem) {
    return mem + d;
}

template <size_t size, size_t index, typename T, T x>
constexpr auto operator+(GeneralPurposeRegister<size, index> r, Immediate<T, x> disp) {
    return _[r] + disp;
}
template <size_t size, size_t index, typename T, T x>
constexpr auto operator+(Immediate<T, x> disp, GeneralPurposeRegister<size, index> r) {
    return r + disp;
}

/**
    Add negative displayment to memory.
*/
template <size_t size, typename reg1, typename reg2, size_t mult, Displacement disp, typename T, T x>
constexpr auto operator-(Memory<size, reg1, reg2, mult, disp>, Immediate<T, x>) {
    return Memory<size, reg1, reg2, mult, disp - x>{};
}
template <size_t size, typename reg1, typename reg2, size_t mult, Displacement disp, typename T, T x>
constexpr auto operator-(Immediate<T, x> d, Memory<size, reg1, reg2, mult, disp> mem) {
    return mem - d;
}

template <size_t size, size_t index, typename T, T x>
constexpr auto operator-(GeneralPurposeRegister<size, index> r, Immediate<T, x> disp) {
    return _[r] - disp;
}
template <size_t size, size_t index, typename T, T x>
constexpr auto operator-(Immediate<T, x> disp, GeneralPurposeRegister<size, index> r) {
    return r - disp;
}

/**
    Create a scaling factor.
*/
template <size_t size, size_t index, typename T, T x>
constexpr auto operator*(GeneralPurposeRegister<size, index> r, Immediate<T, x>) {
    return Memory<size, None, decltype(r), x, 0>{};
}
template <size_t size, size_t index, typename T, T x>
constexpr auto operator*(Immediate<T, x> scale, GeneralPurposeRegister<size, index> r) {
    return r * scale;
}

/**
    Add scaling factor to base reister.
*/
template <size_t size, size_t index, typename reg2, Displacement disp, size_t scaling>
constexpr auto operator+(GeneralPurposeRegister<size, index> reg1, Memory<size, None, reg2, scaling, disp>) {
    return Memory<size, decltype(reg1), reg2, scaling, disp>{};
}
template <size_t size, size_t index, typename reg2, Displacement disp, size_t scaling>
constexpr auto operator+(Memory<size, None, reg2, scaling, disp>, GeneralPurposeRegister<size, index> reg1) {
    return Memory<size, decltype(reg1), reg2, scaling, disp>{};
}

/**
    Combine addresses for scaling
*/
template <size_t size, typename reg1, typename reg2, Displacement disp1, Displacement disp2, size_t scaling>
constexpr auto operator+(Memory<size, reg1, None, 0, disp1>, Memory<size, None, reg2, scaling, disp2>) {
    return Memory<size, reg1, reg2, scaling, disp1 + disp2>{};
}
template <size_t size, typename reg1, typename reg2, Displacement disp1, Displacement disp2, size_t scaling>
constexpr auto operator+(Memory<size, None, reg2, scaling, disp2>, Memory<size, reg1, None, 0, disp1>) {
    return Memory<size, reg1, reg2, scaling, disp1 + disp2>{};
}

/**
    Offset register.
*/
template <size_t size, typename reg1, Displacement disp, size_t reg2Size, size_t reg2Index>
constexpr auto operator+(Memory<size, reg1, None, 0, disp> m, GeneralPurposeRegister<reg2Size, reg2Index> r) {
    return m + r * 1_d;
}
template <size_t size, typename reg1, Displacement disp, size_t reg2Size, size_t reg2Index>
constexpr auto operator+(GeneralPurposeRegister<reg2Size, reg2Index> r, Memory<size, reg1, None, 0, disp> m) {
    return m + r;
}

} // tasm
