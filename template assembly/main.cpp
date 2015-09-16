#include <iostream>

#include <cassert>
#include "asm.h"
#include "label.h"
#include "../instr.h"

template <typename A, typename B>
void check_same(const char* msg, A x, B y) {
    if (!(x == y))
        std::cerr << msg << ": " << x << " != " << y  << std::endl;
}

int main(int argc, const char * argv[]) {
    check_same("Mov literal", 3,
        Asm<int>(
            MOV(eax, 3_d),
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
    
    check_same("Simple loop", 25,
        Asm<int>(
            MOV(ecx, 5_d),
            MOV(eax, 0_d),
        "start"_label,
            CMP(ecx, 0_d),
            JE("done"_rel8),
            ADD(eax, 5_d),
            DEC(ecx),
            JMP("start"_rel8),
        "done"_label,
            RET())()
    );

    check_same("Access arg using esp", 1,
        Asm<int>(
            MOV(eax, _[esp] + 28_d),
            RET())(1, 2, 3)
    );
    
    Print<decltype(_[esp + 10_b][ebp * 2_b])> {};
    
   /*  auto p = Asm<int>(
        MOV(ebx, 1_d),
        MOV(eax, mem(esp)[ebp][ebp]),
        RET());

    std::cout << p(1, 2, 3) << std::endl;
   */
    std::cout << "done" << std::endl;
    return 0;
}
