#pragma once

/**
    State, instruction list pair
*/
template <typename s, typename x>
struct Pair {
    using state = s;
    using value = x;
};

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
        using right = call<call<f, typename left::value>, typename left::state>;
        using type = Pair<typename right::state, append<typename left::value, typename right::value>>;
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

