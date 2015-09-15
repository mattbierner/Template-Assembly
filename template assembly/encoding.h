#pragma once

#include "byte_string.h"
#include "register.h"

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
    Instruction modrm bit.
*/
template <unsigned mode, unsigned reg, unsigned rm>
using modrm = typename IntToBytes<1, (mode << 6) | (reg << 3) | rm>::type;

/**
*/
template <size_t s, size_t i>
constexpr unsigned get_reg(GeneralPurposeRegister<s, i>) {
    return GeneralPurposeRegister<s, i>::index;
};