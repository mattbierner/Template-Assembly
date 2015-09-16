#pragma once

/**
    Call a metafunction with a set of arguments.
*/
template <typename f, typename... args>
using call = typename f::template apply<args...>::type;

/**
    Metafunction that returns `T`.
*/
template <typename T>
struct identity {
    using type = T;
};

/**
*/
template <typename x>
struct Constant {
    template <typename _>
    struct apply {
        using type = x;
    };
};

/**
*/
template <typename f>
struct flip {
    template <typename a, typename b>
    struct apply {
        using type = call<f, b, a>;
    };
};

/**
    Transform a template into a metafunction.
*/
template <template<typename...> class f>
struct mfunc {
    template <typename... args>
    using apply = identity<f<args...>>;
};

/**
    Nothing type.
*/
struct None {};


/**
    State, instruction list pair
*/
template <typename l, typename r>
struct Pair {
    using first = l;
    using second = r;
};