#pragma once

/**
 
*/
template <size_t s, size_t i>
struct GeneralPurposeRegister {
    static constexpr size_t size = s;
    static constexpr size_t index = i;
};

static constexpr auto al = GeneralPurposeRegister<8, 0>{};
static constexpr auto cl = GeneralPurposeRegister<8, 1>{};
static constexpr auto dl = GeneralPurposeRegister<8, 2>{};
static constexpr auto bl = GeneralPurposeRegister<8, 3>{};
static constexpr auto ah = GeneralPurposeRegister<8, 4>{};
static constexpr auto ch = GeneralPurposeRegister<8, 5>{};
static constexpr auto dh = GeneralPurposeRegister<8, 6>{};
static constexpr auto bh = GeneralPurposeRegister<8, 7>{};

static constexpr auto ax = GeneralPurposeRegister<16, 0>{};
static constexpr auto cx = GeneralPurposeRegister<16, 1>{};
static constexpr auto dx = GeneralPurposeRegister<16, 2>{};
static constexpr auto bx = GeneralPurposeRegister<16, 3>{};
static constexpr auto sp = GeneralPurposeRegister<16, 4>{};
static constexpr auto bp = GeneralPurposeRegister<16, 5>{};
static constexpr auto si = GeneralPurposeRegister<16, 6>{};
static constexpr auto di = GeneralPurposeRegister<16, 7>{};

static constexpr auto eax = GeneralPurposeRegister<32, 0>{};
static constexpr auto ecx = GeneralPurposeRegister<32, 1>{};
static constexpr auto edx = GeneralPurposeRegister<32, 2>{};
static constexpr auto ebx = GeneralPurposeRegister<32, 3>{};
static constexpr auto esp = GeneralPurposeRegister<32, 4>{};
static constexpr auto ebp = GeneralPurposeRegister<32, 5>{};
static constexpr auto esi = GeneralPurposeRegister<32, 6>{};
static constexpr auto edi = GeneralPurposeRegister<32, 7>{};
