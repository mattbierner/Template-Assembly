#pragma once

#include <type_traits>

#include "byte_string.h"
#include "functor.h"
#include "list.h"

namespace tasm { namespace instruction {

namespace details {

/**
    Get the offset of a label.
*/
template <size_t size, typename state, typename labelOffset>
struct GetOffset : ::tasm::byte_string::IntToBytes<size, static_cast<long long>(labelOffset::value - state::index)> { };

template <size_t size, typename state>
struct GetOffset<size, state, tasm::details::None> : ::tasm::byte_string::IntToBytes<size, 0> { };

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

template<size_t idx, size_t const * arr>
struct static_accumulate :
   std::integral_constant<size_t, arr[idx] + static_accumulate<idx - 1, arr>::value>
{ };

template<size_t const * arr>
struct static_accumulate<0, arr> : std::integral_constant<size_t, arr[0]>
{ };

} // details

/**
    Encodes a single, basic instruction as a series of bytes.
*/
template <typename... components>
struct Instruction  {
    //static constexpr size_t size = (... + components::size);
    static constexpr size_t sizes[] = { components::size... };
    static constexpr size_t size = details::static_accumulate<sizeof...(components) - 1, sizes>::value;

    template <typename state>
    struct apply {
        using next_state = typename state::template inc<size>;
        using type = tasm::details::Pair<next_state, functional::fold<
            tasm::details::mfunc<byte_string::bytes_join>,
            byte_string::ByteString<>,
            functional::fmap<typename details::Rewrite<next_state>, list::List<components...>>>>;
    };
};

}} // tasm::instruction
