#pragma once

#include <type_traits>

#include "list.h"

namespace tasm {

namespace details {

/**
    Relative offset of a label in a program.
*/
template <size_t x>
using LabelOffset = std::integral_constant<size_t, x>;

} // details

/**
    Name used to identify an assembly label.
*/
template <char... chars>
struct Label {
    template <typename s>
    struct apply {
        using type = details::Pair<typename s::template add_label<Label<chars...>>, byte_string::ByteString<>>;
    };
};

template <typename T, T... chars>
constexpr auto operator""_label() { return Label<chars...>{}; }

/**
    Relative label.
*/
template <size_t s, typename name>
struct Rel { static constexpr size_t size = s; };

template <typename name>
using Rel8 = Rel<1, name>;

template <typename T, T... chars>
constexpr auto operator""_rel8() { return Rel8<Label<chars...>>{}; }

} // tasm