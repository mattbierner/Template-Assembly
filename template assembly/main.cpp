#include <iostream>

#include "list.h"
#include "label.h"
#include "../instr.h"
#include "state.h"


struct XXXX {
    template <typename p, typename c>
    struct apply {
        using type = string_add<to_bytes<p>, to_bytes<c>>;
    };
};

template <typename program,
    typename r1 = call<program, pass1state>>
using compile = 
    fold<
        XXXX,
        String<>,
        typename call<program, pass2state<typename r1::state>>::value>;


/**
    Wrap some template assembly is a standard functor.
    
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
        MOV(eax, DWord<3>()),
        JMP("a"_rel8),
        ADD(eax, DWord<2>()),
        //MOV(eax, ebp),
       // SUB(eax, esp),
        "a"_label,
        RET());

   // P<decltype(p)::program> {};
    std::cout << std::hex << p() << std::endl;
    return 0;
}
