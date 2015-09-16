#pragma once

#include "byte_string.h"
#include "functor.h"
#include "list.h"

namespace Details {

/**
    Get the offset of a label.
*/
template <typename s, typename labelOffset>
struct GetOffset : IntToBytes<1, static_cast<uint8_t>(labelOffset::value - s::index)> { };

template <typename s>
struct GetOffset<s, None> { using type = byte<0>; };

/**
    Functor that rewrites instruction components to replace labels with relative offsets.
*/
template <typename state>
struct Rewrite {
    template <typename x>
    struct apply {
        using type = x;
    };
    
    template <typename x>
    struct apply<Rel8<x>> :
        GetOffset<state, typename state::template lookup_label<x>> {};
};

} // Details

/**
    Encodes a single, basic instruction as a series of bytes.
*/
template <typename... xs>
struct Instruction  {
    static constexpr size_t size = (... + xs::size);
    
    template <typename s>
    struct apply {
        using nexts = typename s::template inc<size>;
        using type = Pair<nexts, fmap<typename Details::Rewrite<nexts>, List<xs...>>>;
    };
};
