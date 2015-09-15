#pragma once

/**
    General purpose x86 register.
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

/**
    One byte GP registers.
*/
static constexpr auto al = GeneralPurposeRegister<1, 0>{};
static constexpr auto cl = GeneralPurposeRegister<1, 1>{};
static constexpr auto dl = GeneralPurposeRegister<1, 2>{};
static constexpr auto bl = GeneralPurposeRegister<1, 3>{};
static constexpr auto ah = GeneralPurposeRegister<1, 4>{};
static constexpr auto ch = GeneralPurposeRegister<1, 5>{};
static constexpr auto dh = GeneralPurposeRegister<1, 6>{};
static constexpr auto bh = GeneralPurposeRegister<1, 7>{};

/**
    Two byte GP registers.
*/
static constexpr auto ax = GeneralPurposeRegister<2, 0>{};
static constexpr auto cx = GeneralPurposeRegister<2, 1>{};
static constexpr auto dx = GeneralPurposeRegister<2, 2>{};
static constexpr auto bx = GeneralPurposeRegister<2, 3>{};
static constexpr auto sp = GeneralPurposeRegister<2, 4>{};
static constexpr auto bp = GeneralPurposeRegister<2, 5>{};
static constexpr auto si = GeneralPurposeRegister<2, 6>{};
static constexpr auto di = GeneralPurposeRegister<2, 7>{};

/**
    Four byte GP registers.
*/
static constexpr auto eax = GeneralPurposeRegister<4, 0>{};
static constexpr auto ecx = GeneralPurposeRegister<4, 1>{};
static constexpr auto edx = GeneralPurposeRegister<4, 2>{};
static constexpr auto ebx = GeneralPurposeRegister<4, 3>{};
static constexpr auto esp = GeneralPurposeRegister<4, 4>{};
static constexpr auto ebp = GeneralPurposeRegister<4, 5>{};
static constexpr auto esi = GeneralPurposeRegister<4, 6>{};
static constexpr auto edi = GeneralPurposeRegister<4, 7>{};

/**
    Eight byte GP registers.
*/
static constexpr auto rax = GeneralPurposeRegister<8, 0>{};
static constexpr auto rcx = GeneralPurposeRegister<8, 1>{};
static constexpr auto rdx = GeneralPurposeRegister<8, 2>{};
static constexpr auto rbx = GeneralPurposeRegister<8, 3>{};
static constexpr auto rsp = GeneralPurposeRegister<8, 4>{};
static constexpr auto rbp = GeneralPurposeRegister<8, 5>{};
static constexpr auto rsi = GeneralPurposeRegister<8, 6>{};
static constexpr auto rdi = GeneralPurposeRegister<8, 7>{};
static constexpr auto r0 = rax;
static constexpr auto r1 = rcx;
static constexpr auto r2 = rdx;
static constexpr auto r3 = rbx;
static constexpr auto r4 = rsp;
static constexpr auto r5 = rbp;
static constexpr auto r6 = rsi;
static constexpr auto r7 = rdi;
static constexpr auto r8 = GeneralPurposeRegister<8, 8>{};
static constexpr auto r9 = GeneralPurposeRegister<8, 9>{};
static constexpr auto r10 = GeneralPurposeRegister<8, 10>{};
static constexpr auto r11 = GeneralPurposeRegister<8, 11>{};
static constexpr auto r12 = GeneralPurposeRegister<8, 12>{};
static constexpr auto r13 = GeneralPurposeRegister<8, 13>{};
static constexpr auto r14 = GeneralPurposeRegister<8, 14>{};
static constexpr auto r15 = GeneralPurposeRegister<8, 15>{};
