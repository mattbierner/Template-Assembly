#pragma once

#include "byte_string.h"
#include "functor.h"
#include "list.h"

namespace Details {

/**
    Get the offset of a label.
*/
template <size_t size, typename state, typename labelOffset>
struct GetOffset : IntToBytes<size, static_cast<long long>(labelOffset::value - state::index)> { };

template <size_t size, typename state>
struct GetOffset<size, state, None> : IntToBytes<size, 0> { };

/**
    Functor that rewrites instruction components to replace labels with relative offsets.
*/
template <typename state>
struct Rewrite {
    template <typename x>
    struct apply {
        using type = x;
    };
    
    template <size_t s, typename x>
    struct apply<Rel<s, x>> :
        GetOffset<s, state, typename state::template lookup_label<x>> {};
};

} // Details

/**
    Encodes a single, basic instruction as a series of bytes.
*/
template <typename... components>
struct Instruction  {
    static constexpr size_t size = (... + components::size);
    
    template <typename state>
    struct apply {
        using next_state = typename state::template inc<size>;
        using type = Pair<next_state, fold<
            mfunc<bytes_join>,
            ByteString<>,
            fmap<typename Details::Rewrite<next_state>, List<components...>>>>;
    };
};
