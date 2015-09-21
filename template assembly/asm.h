 #pragma once

#include "asm_monad.h"
#include "byte_string.h"
#include "foldable.h"
#include "label.h"
#include "instr.h"
#include "state.h"

/**
    Convert an Asm program into machine code.
*/
template <typename program>
using compile = typename call<
    program,
    pass2state<typename call<program, pass1state>::first>>::second;

/**
    Assembly function wrapper.
*/
template <typename R, typename P>
struct AsmProgram {
    using program = P;
    
    template <typename... Args>
    R operator()(Args... args) {
        return ((R(*)(std::decay_t<Args>...))P::data)(args...);
    }
};


/**
    Block of assembly code.
*/
template <typename x, typename... xs>
constexpr auto block(x, xs...) {
    return seq<x, xs...>{};
}

/**
    Create a top level assembly function.
*/
template <typename R, typename x, typename... xs>
constexpr auto Asm(x, xs...) {
    return AsmProgram<R, compile<seq<x, xs...>>>();
}