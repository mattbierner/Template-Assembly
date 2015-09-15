#include <iostream>

#include "list.h"
#include "label.h"
#include "../instr.h"
#include "state.h"


struct XXXX {
    template <typename p, typename c>
    struct apply {
        using type = bytes_add<to_bytes<p>, to_bytes<c>>;
    };
};

template <typename program,
    typename r1 = call<program, pass1state>>
using compile = 
    fold<
        XXXX,
        ByteString<>,
        typename call<program, pass2state<typename r1::first>>::second>;


/**
    Wrap some template assembly is a functor.
    
    @param R Type of value returned from the assembly.
    @param P Assembly byte string.
*/
template <typename R, typename P>
struct AsmProgram {
    using program = P;

    /**
        Invoke the assembly program with a set of arguments
    */
    template <typename... Args>
    R operator()(Args... args) {
        return ((R(*)(...))program::data)(args...);
    }
};

/**
     Assembly block.
*/
template <typename R, typename x, typename... xs>
constexpr auto Asm(x, xs...) {
    return AsmProgram<R, compile<block<x, xs...>>>();
};


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
        MOV(eax, 4_d),
        SUB(eax, 1_d),
        MOV(ecx, eax),
        RET());

 //  P<decltype(x)::program> {};
    std::cout << p() << std::endl;
    std::cout << loop() << std::endl;
    
    std::cout << x() << std::endl;

    return 0;
}
