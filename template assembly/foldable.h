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
