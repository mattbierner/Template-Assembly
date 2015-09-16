#pragma once

/**
    Compile time check that two types are the same.
*/
template <typename a, typename b>
struct assert_is_same;

template <typename a>
struct assert_is_same<a, a> { };


/**
    Compile time print of type.
*/
template <typename...>
struct P;
