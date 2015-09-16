#pragma once

#include "byte_string.h"
#include "foldable.h"
#include "list.h"
#include "state.h"
#include "utility.h"

/**
*/
template <typename x>
struct of {
    template <typename s>
    struct apply {
        using type = Pair<s, x>;
    };
};

/**
*/
template <typename p, typename f>
struct bind {
    template <typename s>
    struct apply {
        using left = call<p, s>;
        using right = call<call<f, typename left::second>, typename left::first>;
        using type = Pair<typename right::first, append<typename left::second, typename right::second>>;
    };
};

/**
*/
template <typename p, typename c>
struct next : bind<p, Constant<c>> { };

/**
*/
template <typename x, typename... xs>
using block = fold<mfunc<next>, x, List<xs...>>;

/**
    Convert an Asm program into machine code.
*/
template <typename program>
using compile = 
    fold<
        mfunc<bytes_join>,
        ByteString<>,
        typename call<program, pass2state<typename call<program, pass1state>::first>>::second>;

/**
*/
template <typename R, typename P>
struct AsmProgram {
    using program = P;
    
    template <typename... Args>
    R operator()(Args... args) {
        return ((R(*)(Args...))P::data)(args...);
    }
};

/**
*/
template <typename R, typename x, typename... xs>
constexpr auto Asm(x, xs...) {
    return AsmProgram<R, compile<block<x, xs...>>>();
}