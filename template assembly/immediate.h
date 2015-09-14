#pragma once

#include "string.h"

/**
*/
template <typename T, T x>
struct Immediate {
    using type = T;
    static constexpr T value = x;
    static constexpr size_t size = sizeof(T);
};

template <uint8_t x>
using Byte = Immediate<uint8_t, x>;

template <uint32_t x>
using Word = Immediate<uint16_t, x>;

template <uint32_t x>
using DWord = Immediate<uint32_t, x>;



template <typename T, T x>
struct ToBytes<Immediate<T, x>> :
    IntToString<sizeof(T) * 8, x> { };
