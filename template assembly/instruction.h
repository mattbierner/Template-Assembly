#pragma once

#include "string.h"

namespace Details {

/**
    Get the offset of a label.
*/
template <typename s, typename labelOffset>
struct GetOffset : IntToBytes<1, static_cast<uint8_t>(labelOffset::value - s::index)> { };

template <typename s>
struct GetOffset<s, None> { using type = byte<0>; };


/**
    Rewrite an instruction to replace labels with relative offset.
*/
template <typename s, typename...>
struct Rewrite {
    using type = List<>;
};

template <typename s, typename x, typename... xs>
struct Rewrite<s, x, xs...> {
    using type = cons<x, typename Rewrite<s, xs...>::type>;
};

template <typename s, typename x, typename... xs>
struct Rewrite<s, Rel8<x>, xs...> {
    using label = typename s::template lookup_label<x>;
    
    using type = cons<typename GetOffset<s, label>::type, typename Rewrite<s, xs...>::type>;
};

}

/**
    Encodes a single, basic instruction as a series of bytes.
*/
template <typename... xs>
struct Instruction  {
    static constexpr size_t size = (... + xs::size);
    
    template <typename s>
    struct apply {
        using nexts = typename s::template inc<size>;
        using type = Pair<nexts, typename Details::Rewrite<nexts, xs...>::type>;
    };
};
