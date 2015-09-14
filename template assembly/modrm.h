#pragma once

#include "register.h"
#include "string.h"

template <unsigned mode, unsigned reg, unsigned rm>
using modrm = typename IntToString<8, (mode << 6) | (reg << 3) | rm>::type;


template <size_t s, size_t i>
constexpr unsigned get_reg(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index;
};