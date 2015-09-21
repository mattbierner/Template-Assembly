#pragma once

#include "foldable.h"
#include "list.h"
#include "utility.h"

/**
    Sequence two state operations.
*/
template <typename p, typename c>
struct next {
    template <typename s>
    struct apply {
        using left = call<p, s>;
        using right = call<c, typename left::first>;
        using type = Pair<
            typename right::first,
            append<typename left::second, typename right::second>>;
    };
};

/**
    Sequence two or more state operations.
*/
template <typename x, typename... xs>
using seq = fold<mfunc<next>, x, List<xs...>>;
