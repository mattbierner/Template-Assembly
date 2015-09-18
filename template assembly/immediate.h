#pragma once

#include "assert.h"
#include "byte_string.h"

/**
    Asm literal value.
*/
template <typename T, T x>
struct Immediate {
    using type = T;
    static constexpr T value = x;
    static constexpr size_t size = sizeof(T);
        
    auto operator-() const { return Immediate<T, static_cast<T>(-x)>{}; }
};

template <typename L, L lx, typename R, R rx>
constexpr auto operator+(Immediate<L, lx>, Immediate<R, rx>) {
    return Immediate<L, static_cast<L>(lx + rx)>{};
}

template <typename L, L lx, typename R, R rx>
constexpr auto operator*(Immediate<L, lx>, Immediate<R, rx>) {
    return Immediate<L, static_cast<L>(lx * rx)>{};
}

template <typename L, L lx, typename R, R rx>
constexpr auto operator-(Immediate<L, lx>, Immediate<R, rx>) {
    return Immediate<L, static_cast<R>(lx - rx)>{};
}

template <typename T, T x>
struct ToBytes<Immediate<T, x>> :
    IntToBytes<sizeof(T), x> { };


namespace Details {

/**
    Get the base of the number system from a number literal plus the digits of
    that literal.
*/
template <char... digits>
struct GetBase : // decimal
    Pair<std::integral_constant<unsigned, 10>, List<std::integral_constant<char, digits>...>> { };

template <char... digits>
struct GetBase<'0', 'x', digits...> : // hex
    Pair<std::integral_constant<unsigned, 16>, List<std::integral_constant<char, digits>...>> { };

template <char... digits>
struct GetBase<'0', 'X', digits...> : // hex
    Pair<std::integral_constant<unsigned, 16>, List<std::integral_constant<char, digits>...>> { };

template <char... digits>
struct GetBase<'0', digits...> : // octal
    Pair<std::integral_constant<unsigned, 8>, List<std::integral_constant<char, digits>...>> { };

/**
    Get the numeric value of a digit.
*/
template <char x, typename enable = void>
struct DigitToValue : std::integral_constant<unsigned, x - '0'> {};

template <char x>
struct DigitToValue<x, std::enable_if_t<(x >= 'a' && x <= 'f')>> : std::integral_constant<unsigned, x - 'a' + 10> {};

template <char x>
struct DigitToValue<x, std::enable_if_t<(x >= 'A' && x <= 'F')>> : std::integral_constant<unsigned, x - 'A' + 10> {};

/**
    Construct an immediate of `T` from a string of digits.
*/
template <typename T, char... values>
struct ImmediateFromString {
    using base = Details::GetBase<values...>;
    
    struct reducer {
        template <typename p, typename c>
        struct apply :
            std::integral_constant<unsigned long long, p::value * base::first::value + DigitToValue<c::value>::value> { };
    };
    
    using type = Immediate<T,
         static_cast<T>(fold<reducer, std::integral_constant<int, 0>, typename base::second>::value)>;
};

} // Details

/**
    Asm byte literal.
*/
template <int8_t x>
using byte = Immediate<int8_t, x>;

template <char... values>
constexpr auto operator ""_b() {
    return typename Details::ImmediateFromString<typename byte<0>::type, values...>::type{};
}

/**
    Asm word literal.
*/
template <int16_t x>
using word = Immediate<int16_t, x>;

template <char... values>
constexpr auto operator ""_w() {
    return typename Details::ImmediateFromString<typename word<0>::type, values...>::type{};
}

/**
    Asm dword literal.
*/
template <int32_t x>
using dword = Immediate<int32_t, x>;

template <char... values>
constexpr auto operator ""_d() {
    return typename Details::ImmediateFromString<typename dword<0>::type, values...>::type{};
}

/**
    Asm qword literal.
*/
template <int64_t x>
using qword = Immediate<int64_t, x>;

template <char... values>
constexpr auto operator ""_q() {
    return typename Details::ImmediateFromString<typename qword<0>::type, values...>::type{};
}

namespace {
constexpr auto test_1_decimal = assert_is_same<byte<4>, decltype(4_b)>();
constexpr auto test_2_decimal = assert_is_same<byte<42>, decltype(42_b)>();
constexpr auto test_neg1_decimal = assert_is_same<byte<-4>, decltype(-4_b)>();
constexpr auto test_clamp = assert_is_same<byte<-127>, decltype(129_b)>();

constexpr auto test_hex = assert_is_same<byte<4>, decltype(0x4_b)>();
constexpr auto test_hex_digit = assert_is_same<byte<10>, decltype(0xa_b)>();
constexpr auto test_hex_digit_uppser = assert_is_same<byte<10>, decltype(0xA_b)>();
constexpr auto test_multi_hex_digit = assert_is_same<byte<95>, decltype(0x5f_b)>();

constexpr auto test_octal_single = assert_is_same<byte<4>, decltype(04_b)>();
constexpr auto test_octal_multi = assert_is_same<byte<39>, decltype(047_b)>();
}
