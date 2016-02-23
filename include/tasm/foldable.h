#pragma once

#include <tasm/utility.h>

namespace tasm { namespace functional {

/**
    Interface for structures that can be folded.
*/
template <typename f, typename z, typename s>
struct Foldable {
    using type = details::call<f, z, s>;
};

template <typename f, typename z, typename s>
using fold = typename Foldable<f, z, s>::type;

}} // tasm::functional