#pragma once

#include "utility.h"

/**
    Interface for structures that can be folded.
*/
template <typename f, typename z, typename s>
struct Foldable {
    using type = call<f, z, s>;
};

template <typename f, typename z, typename s>
using fold = typename Foldable<f, z, s>::type;


/**
    Fold the arguments to the function.
*/
template <typename f, typename z, typename... args>
struct FoldArgs {
    using type = z;
};

template <typename f, typename z, typename... args>
using fold_args = typename FoldArgs<f, z, args...>::type;

template <typename f, typename z, typename x, typename... xs>
struct FoldArgs<f, z, x, xs...> {
    using type = fold_args<f, call<f, z, x>, xs...>;
};