#pragma once

/**
    General x86 register.
*/
template <size_t s, size_t i>
struct GeneralPurposeRegister {
    /**
        Size of the register in bytes.
    */
    static constexpr size_t size = s;
    
    /**
        x86 register identifier.
    */
    static constexpr size_t index = i;
};

static constexpr auto al = GeneralPurposeRegister<1, 0>{};
static constexpr auto cl = GeneralPurposeRegister<1, 1>{};
static constexpr auto dl = GeneralPurposeRegister<1, 2>{};
static constexpr auto bl = GeneralPurposeRegister<1, 3>{};
static constexpr auto ah = GeneralPurposeRegister<1, 4>{};
static constexpr auto ch = GeneralPurposeRegister<1, 5>{};
static constexpr auto dh = GeneralPurposeRegister<1, 6>{};
static constexpr auto bh = GeneralPurposeRegister<1, 7>{};

static constexpr auto ax = GeneralPurposeRegister<2, 0>{};
static constexpr auto cx = GeneralPurposeRegister<2, 1>{};
static constexpr auto dx = GeneralPurposeRegister<2, 2>{};
static constexpr auto bx = GeneralPurposeRegister<2, 3>{};
static constexpr auto sp = GeneralPurposeRegister<2, 4>{};
static constexpr auto bp = GeneralPurposeRegister<2, 5>{};
static constexpr auto si = GeneralPurposeRegister<2, 6>{};
static constexpr auto di = GeneralPurposeRegister<2, 7>{};

static constexpr auto eax = GeneralPurposeRegister<4, 0>{};
static constexpr auto ecx = GeneralPurposeRegister<4, 1>{};
static constexpr auto edx = GeneralPurposeRegister<4, 2>{};
static constexpr auto ebx = GeneralPurposeRegister<4, 3>{};
static constexpr auto esp = GeneralPurposeRegister<4, 4>{};
static constexpr auto ebp = GeneralPurposeRegister<4, 5>{};
static constexpr auto esi = GeneralPurposeRegister<4, 6>{};
static constexpr auto edi = GeneralPurposeRegister<4, 7>{};
