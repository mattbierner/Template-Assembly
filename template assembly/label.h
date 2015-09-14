#pragma once

#include "asm.h"
#include "map.h"
#include "string.h"

/**
    Name used to identify an assembly label.
*/
template <char... chars>
struct Label {
    template <typename s>
    struct apply {
        using type = Pair<typename s::template add_label<Label<chars...>>, List<>>;
    };
};

template <typename T, T... chars>
constexpr auto operator""_label() { return Label<chars...>{}; };

/**
    Information about a label in assembly code.
    
    Includes the name used to identify the label in assembly + the relative
    offset of the label in the program.
*/
template <typename n, size_t off>
struct LabelData {
    using name = n;
    static constexpr size_t offset = off;
};

template <size_t x>
struct Offset {
    static constexpr size_t value = x;
};






template <typename name>
struct Rel8 { static constexpr size_t size = 1; };

template <typename T, T... chars>
constexpr auto operator""_rel8() { return Rel8<Label<chars...>>{}; };

