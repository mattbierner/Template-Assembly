#pragma once

#include "foldable.h"
#include "functor.h"
#include "string.h"

/**
    Instruction components.
*/
template <char... codes>
using Prefix = String<codes...>;

template <char... codes>
using Opcode = String<codes...>;


template <typename s, typename...>
struct Rewrite {
    using type = List<>;
};

template <typename s, typename x, typename... xs>
struct Rewrite<s, x, xs...> {
    using type = cons<x, typename Rewrite<s, xs...>::type>;
};

template <typename s, typename labelOffset>
struct GetOffset { using type = Byte<labelOffset::value - s::index>; };

template <typename s>
struct GetOffset<s, None> { using type = Byte<0>; };


template <typename s, typename x, typename... xs>
struct Rewrite<s, Rel8<x>, xs...> {
   
    using label = typename s::template lookup_label<x>;
    
    using type = cons<typename GetOffset<s, label>::type, typename Rewrite<s, xs...>::type>;
};



/**
    Encodes a single, basic instruction as a series of bytes.
*/
template <typename... xs>
struct Instruction  {
    static constexpr size_t size = (... + xs::size);
    
    template <typename s>
    struct apply {
        using nexts = typename s::template inc<size>;
        using type = Pair<nexts, typename Rewrite<nexts, xs...>::type>;
    };
};

/*------------------------------------------------------------------------------
    Functor
*/
template <typename f, typename... codes>
struct FMap<f, Instruction<codes...>> {
    using type = Instruction<fmap<f, codes>...>;
};

/*------------------------------------------------------------------------------
    Foldable
*/
template <typename f, typename z, typename... codes>
struct Foldable<f, z, Instruction<codes...>> {
    using type = fold_args<f, z, codes...>;
};