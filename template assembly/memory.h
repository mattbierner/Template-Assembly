#pragma once

#include "immediate.h"
#include "register.h"

/**
    Asm memory address.
*/
template <
    size_t size,
    typename reg,
    typename reg2,
    size_t mult,
    size_t disp>
struct Memory { };

/**
    Add a displayment to some memory.
*/
template <size_t size, typename reg, typename reg2, size_t mult, size_t disp, typename T, T x>
constexpr auto operator+(Memory<size, reg, reg2, mult, disp>, Immediate<T, x>) {
    return Memory<size, reg, reg2, mult, disp + x>{};
}

/**
*/
template <char... values>
constexpr auto operator ""_displacement() {
    return typename Details::ImmediateFromString<typename word<0>::type, values...>::type{};
}


/**
*/
template <typename reg>
constexpr auto mem(reg) {
    return Memory<reg::size, reg, None, 0, 0> {};
}

/**
    Displayment only address.
*/
template <size_t size, typename T, T x>
constexpr auto mem(Immediate<T, x>) {
    static_assert(x < 0xffff, "Displacement too large");
    return Memory<size, None, None, 0, x> {};
}
