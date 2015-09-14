#pragma once

/**
*/
template <char... chars>
struct String {
    static constexpr size_t size = sizeof...(chars);

    static const char data[sizeof...(chars)];
};

template <char... chars>
const char String<chars...>::data[] = { chars... };

template <typename T, T... chars>
constexpr auto operator""_string() {
    return String<chars...>{};
};


template <typename>
struct ToBytes;

template <char... characters>
struct ToBytes<String<characters...>> {
    using type = String<characters...>;
};


template <typename x>
using to_bytes = typename ToBytes<x>::type;


/**
*/
template <typename l, typename r>
struct StringAdd;

template <char... ls, char... rs>
struct StringAdd<String<ls...>, String<rs...>> {
    using type = String<ls..., rs...>;
};

template <typename l, typename r>
using string_add = typename StringAdd<to_bytes<l>, to_bytes<r>>::type;

/**
*/
template <typename...>
struct StringJoin {
    using type = String<>;
};

template <typename x, typename... xs>
struct StringJoin<x, xs...> {
    using type = string_add<x, typename StringJoin<xs...>::type>;
};

template <typename... args>
using string_join = typename StringJoin<args...>::type;


/**
*/
template <size_t s, char c>
struct StringGen {
    using type = string_add<String<c>, typename StringGen<s - 1, c>::type>;
};

template <char c>
struct StringGen<0, c> {
    using type = String<>;
};

template <size_t s, char c>
using string_gen = typename StringGen<s, c>::type;

/**
*/
template <size_t size, typename s>
using string_pack = string_add<string_gen<size / 4 - s::size, '\0'>, s>;





template <size_t count, unsigned x>
struct IntToString {
    using type = string_add<
        String<static_cast<char>(x & 0xff)>,
        typename IntToString<count - 8, (x >> 8)>::type>;
};

template <unsigned x>
struct IntToString<0, x> {
    using type = String<>;
};

template <size_t count, typename x>
using to_string = typename IntToString<count, x::value>::type;

