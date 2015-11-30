#include "catch.hpp"

#include "asm.h"

template <typename Count, typename... Body>
constexpr auto do_x_times(Count count, Body... body)
{
    return block(
        MOV(ecx, count),
    "start"_label,
        CMP(ecx, 0_d),
        JE("done"_rel8),
        body...,
        DEC(ecx),
        JMP("start"_rel8),
    "done"_label);
}

int ret66() { return 66; }

TEST_CASE("Features Test", "[asm]") {

  SECTION("Mov literal") {
    REQUIRE(Asm<int>(
            MOV(eax, 3_d),
            RET())()
            == 3);
  }

  SECTION("64 bit register MOV") {
    REQUIRE(Asm<int>(
            MOV(rax, 6_q),
            RET())()
            == 6);
  }

  SECTION("Negative literal") {
    REQUIRE(Asm<int>(
            MOV(eax, -3_d),
            ADD(eax, - - -100_d),
            RET())()
            == -103);
  }

  SECTION("Move reg to reg") {
    REQUIRE(Asm<int>(
            MOV(ecx, 4_d),
            MOV(eax, ecx),
            RET())()
            == 4);
  }

  SECTION("Simple jmp") {
    REQUIRE(Asm<int>(
            MOV(eax, 3_d),
            JMP("a"_rel8),
            ADD(eax, 2_d),
            "a"_label,
            RET())()
            == 3);
  }

  SECTION("Simple loop") {
    REQUIRE(Asm<int>(
            MOV(ecx, 5_d),
            MOV(eax, 0_d),
            "start"_label,
            CMP(ecx, 0_d),
            JE("done"_rel8),
            ADD(eax, 6_d),
            DEC(ecx),
            JMP("start"_rel8),
            "done"_label,
            RET())()
            == 30);
  }

  SECTION("Macro simple loop") {
    REQUIRE(Asm<int>(
            MOV(eax, 0_d),
            do_x_times(5_d,
                ADD(eax, 6_d)),
            RET())()
            == 30);
  }

  SECTION("Access arg using esp") {
    REQUIRE(Asm<int>(
            MOV(eax, _[esp + 28_d]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Access arg using ebp") {
    REQUIRE(Asm<int>(
            MOV(eax, _[ebp - 0xc_b]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Index ebp") {
    REQUIRE(Asm<int>(
            MOV(ecx, 2_d),
            MOV(eax, _[ebp + ecx * 2_b - 0x10_d]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Access args using ebp and division") {
    REQUIRE(Asm<int>(
            MOV(edx, 0_d),
            MOV(eax, _[ebp - 0xc_b]),
            MOV(ecx, _[ebp - 0x10_b]),
            DIV(ecx),
            MOV(ecx, _[ebp - 0x14_b]),
            DIV(ecx),
            RET())(100, 5, 4)
            == 5);
  }

  SECTION("Access arg with 64 bit reg") {
    REQUIRE(Asm<int>(
            MOV(rax, _[rsp + 24_d]),
            RET())(1, 2, 3)
            == 2);
  }

  SECTION("Access second register zero") {
    REQUIRE(Asm<int>(
            MOV(ecx, 0_d),
            MOV(eax, _[esp + 28_d + ecx]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Access second register with offset") {
    REQUIRE(Asm<int>(
            MOV(ecx, 8_d),
            MOV(eax, _[esp + 20_d + ecx]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Access second register with offset and 1 scale") {
    REQUIRE(Asm<int>(
            MOV(ecx, 8_d),
            MOV(eax, _[esp + 20_d + ecx * 1_b]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Access second register with offset and 4 scale") {
    REQUIRE(Asm<int>(
            MOV(ecx, 2_d),
            MOV(eax, _[esp + 20_d + ecx * 4_b]),
            RET())(1, 2, 3)
            == 1);
  }

  SECTION("Call c function from assembly") {
    REQUIRE(Asm<int>(
            MOV(rbx, _[rsp + 8_d]),
            CALL(rbx),
            ADD(eax, 2_d),
            RET())(&ret66)
            == 68);
  }

  SECTION("Call c function from esp directly") {
    REQUIRE(Asm<int>(
            CALL(_[rsp + 8_d]),
            RET())(&ret66)
            == 66);
  }

  SECTION("Call c function from ebp directly") {
    REQUIRE(Asm<int>(
            CALL(_[rbp - 0x10_d]),
            RET())(&ret66)
            == 66);
  }

  SECTION("Call c function from rdi directly") {
    REQUIRE(Asm<int>(
            CALL(rdi),
            RET())(&ret66)
            == 66);
  }
}
