#include "catch.hpp"

#include <type_traits>
#include <tasm/asm.h>

using namespace tasm;

TEST_CASE("Compile time immediate tests", "[compile][immediate]") {

  constexpr auto test_1_decimal = std::is_same<byte<4>, decltype(4_b)>();
  constexpr auto test_2_decimal = std::is_same<byte<42>, decltype(42_b)>();
  constexpr auto test_neg1_decimal = std::is_same<byte<-4>, decltype(-4_b)>();
  constexpr auto test_clamp = std::is_same<byte<-127>, decltype(129_b)>();

  constexpr auto test_hex = std::is_same<byte<4>, decltype(0x4_b)>();
  constexpr auto test_hex_digit = std::is_same<byte<10>, decltype(0xa_b)>();
  constexpr auto test_hex_digit_uppser = std::is_same<byte<10>, decltype(0xA_b)>();
  constexpr auto test_multi_hex_digit = std::is_same<byte<95>, decltype(0x5f_b)>();

  constexpr auto test_octal_single = std::is_same<byte<4>, decltype(04_b)>();
  constexpr auto test_octal_multi = std::is_same<byte<39>, decltype(047_b)>();

  constexpr auto test_fdas = std::is_same<byte<12>, decltype(1'2_b)>();

  SECTION("1 decimal") {
    CHECK(test_1_decimal);
  }

  SECTION("2 decimal") {
    CHECK(test_2_decimal);
  }

  SECTION("neg1 decimal") {
    CHECK(test_neg1_decimal);
  }

  SECTION("clamp") {
    CHECK(test_clamp);
  }

  SECTION("hexadecimal") {
    CHECK(test_hex);
  }

  SECTION("hexadecimal digit") {
    CHECK(test_hex_digit);
  }

  SECTION("hexadecimal upper digit") {
    CHECK(test_hex_digit_uppser);
  }

  SECTION("hexadecimal multi digit") {
    CHECK(test_multi_hex_digit);
  }

  SECTION("1 octal") {
    CHECK(test_octal_single);
  }

  SECTION("2 octal") {
    CHECK(test_octal_multi);
  }

  SECTION("fdas") {
    CHECK(test_fdas);
  }
}
