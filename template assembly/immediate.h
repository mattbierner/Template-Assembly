#pragma once

#include "byte_string.h"

/**
*/
template <typename T, T x>
struct Immediate {
    using type = T;
    static constexpr T value = x;
    static constexpr size_t size = sizeof(T);
};

template <int8_t x>
using byte = Immediate<int8_t, x>;

template <int16_t x>
using word = Immediate<int16_t, x>;

template <int32_t x>
using dword = Immediate<int32_t, x>;


template <typename T, T x>
struct ToBytes<Immediate<T, x>> :
    IntToBytes<sizeof(T), x> { };
