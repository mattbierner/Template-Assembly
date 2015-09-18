#pragma once

/**
    String of byte data.
*/
template <char... chars>
struct ByteString {
    static constexpr size_t size = sizeof...(chars);
    static const char data[sizeof...(chars)];
};

template <char... chars>
const char ByteString<chars...>::data[] = { chars... };

/**
    Interface for a type that can be converted to a byte string.
*/
template <typename>
struct ToBytes;

template <char... characters>
struct ToBytes<ByteString<characters...>> {
    using type = ByteString<characters...>;
};

template <typename x>
using to_bytes = typename ToBytes<x>::type;


/**
    Combine to byte strings.
*/
template <typename l, typename r>
struct BytesAdd;

template <char... ls, char... rs>
struct BytesAdd<ByteString<ls...>, ByteString<rs...>> {
    using type = ByteString<ls..., rs...>;
};

template <typename l, typename r>
using bytes_add = typename BytesAdd<to_bytes<l>, to_bytes<r>>::type;

/**
    Combine 1 ore more byte strings.
*/
template <typename...>
struct BytesJoin {
    using type = ByteString<>;
};

template <typename x, typename... xs>
struct BytesJoin<x, xs...> {
    using type = bytes_add<x, typename BytesJoin<xs...>::type>;
};

template <typename... args>
using bytes_join = typename BytesJoin<args...>::type;

/**
    Convert a number to a byte string of `size` bytes.
*/
template <size_t count, long long x>
struct IntToBytes {
    using type = bytes_add<
        ByteString<static_cast<char>(x & 0xff)>,
        typename IntToBytes<count - 1, (x >> 8)>::type>;
};

template <long long x>
struct IntToBytes<0, x> {
    using type = ByteString<>;
};
