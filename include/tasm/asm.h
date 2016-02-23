#pragma once
#include <stddef.h> // size_t definition

#include <tasm/execute.h>
#include <tasm/byte_string.h>
#include <tasm/foldable.h>
#include <tasm/label.h>
#include <tasm/bytes.h>
#include <tasm/state.h>

#include "instr.h"

namespace tasm {

/**
    Convert an Asm program into machine code.
*/
template <typename program>
using assemble = typename details::call<
    program,
    state::pass2state<typename details::call<program, state::pass1state>::first>>::second;

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
    return execute::seq<x, xs...>{};
}

/**
    Create a top level assembly function.
*/
template <typename R, typename x, typename... xs>
constexpr auto Asm(x, xs...) {
    return AsmProgram<R, assemble<execute::seq<x, xs...>>>();
}

} // tasm
