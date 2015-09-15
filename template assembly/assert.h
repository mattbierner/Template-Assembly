#pragma once

/**
*/
template <typename a, typename b>
struct assert_is_same;

template <typename a>
struct assert_is_same<a, a> { };

