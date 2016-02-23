#pragma once
#include <stddef.h> // size_t definition

#include "asm_monad.h"
#include "byte_string.h"
#include "foldable.h"
#include "label.h"
#include "bytes.h"
#include "instr.h"
#include "state.h"

namespace tasm {

/**
    Convert an Asm program into machine code.
*/
template <typename program>
using assemble = typename details::call<
    program,
    pass2state<typename details::call<program, pass1state>::first>>::second;

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
    return details::seq<x, xs...>{};
}

/**
    Create a top level assembly function.
*/
template <typename R, typename x, typename... xs>
constexpr auto Asm(x, xs...) {
    return AsmProgram<R, assemble<details::seq<x, xs...>>>();
}

} // tasm
