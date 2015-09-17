#pragma once

#include "immediate.h"
#include "register.h"

/**
    Scaling factor.
*/
template <typename base, size_t mult>
struct Scaling { };

using Displacement = int32_t;

/**
    Asm memory address.
    
    Suppored syntaxes:
    
        _[eax]    [eax]
        _[4_b]    [4]
 
        _[eax + 4_b]        4[eax]
 
        _[eax][ecx]         [eax][ecx]
        _[eax + 4_b][ecx]   4[eax][ecx]
        _[eax][ecx * 2_b]        [eax][ecx * 2]
        _[eax + 4_b][ecx * 2_b]     4[eax][ecx * 2]
*/
template <
    size_t size,
    typename reg1,
    typename reg2,
    size_t mult,
    Displacement disp>
struct Memory {
    static_assert(mult == 0 || mult == 1 || mult == 2 || mult == 4 || mult == 8, "Invalid scale.");
    
    /**
        Scale the memory adddress.
    */
    template <size_t rSize, size_t rIndex>
    constexpr auto operator[](GeneralPurposeRegister<rSize, rIndex> r) {
        return operator[](Scaling<decltype(r), 1>{});
    }
    
    template <typename sBase, size_t sMult>
    constexpr auto operator[](Scaling<sBase, sMult>) {
        static_assert(!std::is_same<reg1, None>::value, "Scale requires register.");
        static_assert(std::is_same<reg2, None>::value, "Only single scale allowed.");
        return Memory<size, reg1, sBase, sMult, disp>{};
    }
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

template <size_t size, size_t index, typename T, T x>
constexpr auto operator+(GeneralPurposeRegister<size, index> r, Immediate<T, x> disp) {
    return _[r] + disp;
}

/**
    Add negative displayment to memory.
*/
template <size_t size, typename reg1, typename reg2, size_t mult, Displacement disp, typename T, T x>
constexpr auto operator-(Memory<size, reg1, reg2, mult, disp>, Immediate<T, x>) {
    return Memory<size, reg1, reg2, mult, disp - x>{};
}

template <size_t size, size_t index, typename T, T x>
constexpr auto operator-(GeneralPurposeRegister<size, index> r, Immediate<T, x> disp) {
    return _[r] - disp;
}

/**
    Create a scaling factor.
    
    Should be used within a subscript operator to create a scaled memory address.
*/
template <size_t size, size_t index, typename T, T x>
constexpr auto operator*(GeneralPurposeRegister<size, index> r, Immediate<T, x>) {
    return Scaling<decltype(r), x>{};
}


