#include <iostream>

#include "asm.h"
#include "label.h"
#include "../instr.h"

int main(int argc, const char * argv[]) {

    auto p = Asm<int>(
        MOV(eax, 3_d),
        JMP("a"_rel8),
        ADD(eax, 2_d),
    "a"_label,
        RET());

    auto loop = Asm<int>(
        MOV(ecx, 5_d),
        MOV(eax, 0_d),
    "start"_label,
        CMP(ecx, 0_d),
        JE("done"_rel8),
        ADD(eax, 5_d),
        DEC(ecx),
        JMP("start"_rel8),
    "done"_label,
        RET());

    auto x = Asm<int>(
      //  MOV(eax, 0_d),
        MOV(eax, mem(esp) + 28_d),
        RET());
   
 //   Print<decltype(x)::program> {};
    std::cout << p() << std::endl;
    std::cout << loop() << std::endl;
    
    std::cout << x(1, 2, 3) << std::endl;

    return 0;
}
