#pragma once

namespace tasm {

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
constexpr auto al = GeneralPurposeRegister<1, 0>{};
constexpr auto cl = GeneralPurposeRegister<1, 1>{};
constexpr auto dl = GeneralPurposeRegister<1, 2>{};
constexpr auto bl = GeneralPurposeRegister<1, 3>{};
constexpr auto ah = GeneralPurposeRegister<1, 4>{};
constexpr auto ch = GeneralPurposeRegister<1, 5>{};
constexpr auto dh = GeneralPurposeRegister<1, 6>{};
constexpr auto bh = GeneralPurposeRegister<1, 7>{};

/**
    Two byte GP registers.
*/
constexpr auto ax = GeneralPurposeRegister<2, 0>{};
constexpr auto cx = GeneralPurposeRegister<2, 1>{};
constexpr auto dx = GeneralPurposeRegister<2, 2>{};
constexpr auto bx = GeneralPurposeRegister<2, 3>{};
constexpr auto sp = GeneralPurposeRegister<2, 4>{};
constexpr auto bp = GeneralPurposeRegister<2, 5>{};
constexpr auto si = GeneralPurposeRegister<2, 6>{};
constexpr auto di = GeneralPurposeRegister<2, 7>{};

/**
    Four byte GP registers.
*/
constexpr auto eax = GeneralPurposeRegister<4, 0>{};
constexpr auto ecx = GeneralPurposeRegister<4, 1>{};
constexpr auto edx = GeneralPurposeRegister<4, 2>{};
constexpr auto ebx = GeneralPurposeRegister<4, 3>{};
constexpr auto esp = GeneralPurposeRegister<4, 4>{};
constexpr auto ebp = GeneralPurposeRegister<4, 5>{};
constexpr auto esi = GeneralPurposeRegister<4, 6>{};
constexpr auto edi = GeneralPurposeRegister<4, 7>{};

/**
    Eight byte GP registers.
*/
constexpr auto rax = GeneralPurposeRegister<8, 0>{};
constexpr auto rcx = GeneralPurposeRegister<8, 1>{};
constexpr auto rdx = GeneralPurposeRegister<8, 2>{};
constexpr auto rbx = GeneralPurposeRegister<8, 3>{};
constexpr auto rsp = GeneralPurposeRegister<8, 4>{};
constexpr auto rbp = GeneralPurposeRegister<8, 5>{};
constexpr auto rsi = GeneralPurposeRegister<8, 6>{};
constexpr auto rdi = GeneralPurposeRegister<8, 7>{};
constexpr auto r0 = rax;
constexpr auto r1 = rcx;
constexpr auto r2 = rdx;
constexpr auto r3 = rbx;
constexpr auto r4 = rsp;
constexpr auto r5 = rbp;
constexpr auto r6 = rsi;
constexpr auto r7 = rdi;
constexpr auto r8 = GeneralPurposeRegister<8, 8>{};
constexpr auto r9 = GeneralPurposeRegister<8, 9>{};
constexpr auto r10 = GeneralPurposeRegister<8, 10>{};
constexpr auto r11 = GeneralPurposeRegister<8, 11>{};
constexpr auto r12 = GeneralPurposeRegister<8, 12>{};
constexpr auto r13 = GeneralPurposeRegister<8, 13>{};
constexpr auto r14 = GeneralPurposeRegister<8, 14>{};
constexpr auto r15 = GeneralPurposeRegister<8, 15>{};

} // tasm