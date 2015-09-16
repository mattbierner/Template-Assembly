#pragma once

#include "foldable.h"
#include "functor.h"

/**
    Ordered list of types.
*/
template <typename... elements>
struct List {
    static constexpr size_t size = sizeof...(elements);
};

/**
    Get the head of an list
*/
template <typename list>
struct Car;

template <typename x, typename... xs>
struct Car<List<x, xs...>> {
    using type = x;
};

template <typename list>
using car = typename Car<list>::type;

/**
    Get the rest of a list, excluding the head.
*/
template <typename list>
struct Cdr;

template <typename x, typename... xs>
struct Cdr<List<x, xs...>> {
    using type = List<xs...>;
};

template <typename list>
using cdr = typename Cdr<list>::type;

/**
    Car helpers
*/
template <typename list>
using caar = car<cdr<list>>;

template <typename list>
using caaar = car<cdr<cdr<list>>>;

/**
    Prepend a value onto a list
*/
template <typename x, typename list>
struct Cons;

template <typename x, typename... xs>
struct Cons<x, List<xs...>> {
     using type = List<x, xs...>;
};

template <typename x, typename list>
using cons = typename Cons<x, list>::type;

/**
*/
template <typename l, typename r>
struct Append;

template <typename l, typename r>
using append = typename Append<l, r>::type;

template <typename... ls, typename... rs>
struct Append<List<ls...>, List<rs...>> {
    using type = List<ls..., rs...>;
};

/*------------------------------------------------------------------------------
    Foldable
*/
template <typename f, typename z>
struct Foldable<f, z, List<>> {
    using type = z;
};

template <typename f, typename z, typename x, typename... xs>
struct Foldable<f, z, List<x, xs...>> {
    using type = fold<f, call<f, z, x>, List<xs...>>;
};

/*------------------------------------------------------------------------------
    Functor
*/
template <typename f, typename... elements>
struct FMap<f, List<elements...>> {
    using type = List<call<f, elements>...>;
};

