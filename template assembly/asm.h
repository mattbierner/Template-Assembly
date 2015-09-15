#pragma once

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

