#include <iostream>

#include <cassert>
#include "asm.h"

template <typename A, typename B>
void check_same(const char* msg, A x, B y) {
    if (!(x == y))
        std::cerr << msg << ": " << x << " != " << y  << std::endl;
}

template <typename A, typename B>
void check_same(const char* msg, A* x, B* y) {
    if (!(x == y))
        printf("%s: %p != %p\n", msg, x, y);
}

template <typename Count, typename... Body>
constexpr auto do_x_times(Count count, Body... body)
{
    return block(
        MOV(ecx, count),
    "start"_label,
        CMP(ecx, 0_d),
        JE("done"_rel8),
        body...,
        DEC(ecx),
        JMP("start"_rel8),
    "done"_label);
}

int ret66() { return 66; }

char str[] = "abc";

int main(int argc, const char * argv[]) {
    check_same("Mov literal", 3,
        Asm<int>(
            MOV(eax, 3_d),
            RET())()
    );
        
    check_same("64 bit register MOV", 6,
        Asm<int>(
            MOV(rax, 6_q),
            RET())()
    );
    
    check_same("Negative literal", -103,
        Asm<int>(
            MOV(eax, -3_d),
            ADD(eax, - - -100_d),
            RET())()
    );
    
    check_same("Move reg to reg", 4,
        Asm<int>(
            MOV(ecx, 4_d),
            MOV(eax, ecx),
            RET())()
    );
    
    check_same("Simple jmp", 3,
        Asm<int>(
            MOV(eax, 3_d),
            JMP("a"_rel8),
            ADD(eax, 2_d),
        "a"_label,
            RET())()
    );
    
    check_same("Simple loop", 30,
        Asm<int>(
            MOV(ecx, 5_d),
            MOV(eax, 0_d),
        "start"_label,
            CMP(ecx, 0_d),
            JE("done"_rel8),
            ADD(eax, 6_d),
            DEC(ecx),
            JMP("start"_rel8),
        "done"_label,
            RET())()
    );
    
    check_same("Macro simple loop", 30,
        Asm<int>(
            MOV(eax, 0_d),
            do_x_times(5_d,
                ADD(eax, 6_d)),
            RET())()
    );

    check_same("Access arg using esp", 1,
        Asm<int>(
            MOV(eax, _[esp + 28_d]),
            RET())(1, 2, 3)
    );
    
    check_same("Access arg using ebp", 5,
        Asm<int>(
            MOV(edx, 0_d),
            MOV(eax, _[ebp - 0xc_b]),
            MOV(ecx, _[ebp - 0x10_b]),
            DIV(ecx),
            MOV(ecx, _[ebp - 0x14_b]),
            DIV(ecx),
            RET())(100, 5, 4)
    );
    
    check_same("Access arg with 64 bit reg", 2,
        Asm<int>(
            MOV(rax, _[rsp + 24_d]),
            RET())(1, 2, 3)
    );
    
    check_same("Access second register zero", 1,
        Asm<int>(
            MOV(ecx, 0_d),
            MOV(eax, _[esp + 28_d][ecx]),
            RET())(1, 2, 3)
    );
    
    check_same("Access second register with offset", 1,
        Asm<int>(
            MOV(ecx, 8_d),
            MOV(eax, _[esp + 20_d][ecx]),
            RET())(1, 2, 3)
    );
    
    check_same("Access second register with offset and 1 scale", 1,
        Asm<int>(
            MOV(ecx, 8_d),
            MOV(eax, _[esp + 20_d][ecx * 1_b]),
            RET())(1, 2, 3)
    );

    check_same("Access second register with offset and 4 scale", 1,
        Asm<int>(
            MOV(ecx, 2_d),
            MOV(eax, _[esp + 20_d][ecx * 4_b]),
            RET())(1, 2, 3)
    );
    
    check_same("Call c function from assembly", 66,
        Asm<int>(
            MOV(rax, _[rsp + 8_d]),
            CALL(rax),
            RET())(&ret66)
    );

    check_same("Call c function from assembly memory directly", 66,
        Asm<int>(
            CALL(_[rsp + 8_d]),
            RET())(&ret66)
    );

    auto p = Asm<int>(MOV(eax, _[ebp + 8_d]));
    
    //Print<decltype(p)::program> x{};

    std::cout << "done" << std::endl;
    return 0;
}
