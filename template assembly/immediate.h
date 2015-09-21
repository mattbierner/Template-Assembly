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
        
    constexpr auto operator-() const {
        return Immediate<T, static_cast<T>(-x)>{};
    }
};

template <typename L, L lx, typename R, R rx>
constexpr auto operator+(Immediate<L, lx>, Immediate<R, rx>) {
    return Immediate<L, static_cast<L>(lx + rx)>{};
}

template <typename L, L lx, typename R, R rx>
constexpr auto operator-(Immediate<L, lx>, Immediate<R, rx>) {
    return Immediate<L, static_cast<R>(lx - rx)>{};
}

template <typename L, L lx, typename R, R rx>
constexpr auto operator*(Immediate<L, lx>, Immediate<R, rx>) {
    return Immediate<L, static_cast<L>(lx * rx)>{};
}

template <typename T, T x>
struct ToBytes<Immediate<T, x>> :
    IntToBytes<Immediate<T, x>::size, x> { };


namespace Details {

constexpr unsigned digit_to_value(char c) {
    if      (c >= 'a' && c <= 'f') return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    else if (c >= '0' && c <= '9') return c - '0';
    else                           throw std::invalid_argument("c");
}

template <typename sum, char... digits>
struct GetDigits {
    using type = sum;
};

template <unsigned... existing, char... xs>
struct GetDigits<std::integer_sequence<unsigned, existing...>, '\'', xs...> :
    GetDigits<
        std::integer_sequence<unsigned, existing...>,
        xs...> { };

template <unsigned... existing, char x, char... xs>
struct GetDigits<std::integer_sequence<unsigned, existing...>, x, xs...> :
    GetDigits<
        std::integer_sequence<unsigned, existing..., digit_to_value(x)>,
        xs...> { };

template <unsigned b, char... d>
struct BaseAndDigits {
    static constexpr unsigned base = b;
    using digits = typename GetDigits<std::integer_sequence<unsigned>, d...>::type;
};

template <char... digits>
struct ParseNumber : BaseAndDigits<10, digits...> { };

template <char... digits>
struct ParseNumber<'0', 'X', digits...> : BaseAndDigits<16, digits...> { };

template <char... digits>
struct ParseNumber<'0', 'x', digits...> : BaseAndDigits<16, digits...> { };

template <char... digits>
struct ParseNumber<'0', digits...> : BaseAndDigits<8, digits...> { };

template <char... digits>
struct ParseNumber<'0', 'b', digits...> : BaseAndDigits<2, digits...> { };

template <char... digits>
struct ParseNumber<'0', 'B', digits...> : BaseAndDigits<2, digits...> { };

template <typename T, char... values>
struct ImmediateFromString {
    using number = ParseNumber<values...>;
    
    template <unsigned x, unsigned... xs>
    static constexpr unsigned long long fold(unsigned long sum, std::integer_sequence<unsigned, x, xs...>) {
        return fold(x + number::base * sum, std::integer_sequence<unsigned, xs...>{});
    }
    
    static constexpr unsigned long long fold(unsigned long sum, std::integer_sequence<unsigned>) {
        return sum;
    }
    
    using type = Immediate<T, static_cast<T>(fold(0, typename number::digits{}))>;
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

constexpr auto fdas = assert_is_same<byte<12>, decltype(1'2_b)>();

}
