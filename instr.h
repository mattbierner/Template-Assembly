#pragma once
#include "immediate.h"
#include "instruction.h"
#include "modrm.h"
#include "register.h"
#include "string.h"
constexpr auto AAA() {
            return Instruction<Opcode<'\x37'>>{};
        };
constexpr auto AAD() {
            return Instruction<Opcode<'\xD5'>, Opcode<'\x0A'>>{};
        };
template <uint8_t a>
        constexpr auto AAD(Byte<a>) {
            return Instruction<Opcode<'\xD5'>, to_string<1, Byte<a>>>{};
        };
constexpr auto AAM() {
            return Instruction<Opcode<'\xD4'>, Opcode<'\x0A'>>{};
        };
template <uint8_t a>
        constexpr auto AAM(Byte<a>) {
            return Instruction<Opcode<'\xD4'>, to_string<1, Byte<a>>>{};
        };
constexpr auto AAS() {
            return Instruction<Opcode<'\x3F'>>{};
        };

template <size_t a, uint8_t b>
        constexpr auto ADC(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 2, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto ADC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x10'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ADC(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 2, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto ADC(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 2, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto ADC(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x11'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ADC(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto ADC(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto ADC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x11'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };









template <size_t a, size_t b>
        constexpr auto ADCX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ADD(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto ADD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x00'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ADD(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 0, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto ADD(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 0, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto ADD(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x01'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ADD(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 0, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto ADD(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 0, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto ADD(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };





















template <size_t a, size_t b>
        constexpr auto ADOX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Prefix<'\xF3'>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };














template <size_t a, uint8_t b>
        constexpr auto AND(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 4, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto AND(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x20'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto AND(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 4, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto AND(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 4, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto AND(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x21'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto AND(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto AND(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto AND(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x21'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };









template <size_t a, size_t b, size_t c>
        constexpr auto ANDN(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF2'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, c>{})>>{};
        };









template <size_t a, size_t b, uint32_t c>
        constexpr auto BEXTR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, DWord<c>) {
            return Instruction<Opcode<'\x10'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>, to_string<4, DWord<c>>>{};
        };
template <size_t a, size_t b, size_t c>
        constexpr auto BEXTR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };




template <size_t a, size_t b>
        constexpr auto BLCFILL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 1, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto BLCI(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x02'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto BLCIC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 5, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto BLCMSK(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x02'>, modrm<3, 1, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto BLCS(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 3, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };











template <size_t a, size_t b>
        constexpr auto BLSFILL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto BLSI(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\xF3'>, modrm<3, 3, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto BLSIC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto BLSMSK(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\xF3'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto BLSR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\xF3'>, modrm<3, 1, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto BSF(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBC'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto BSF(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBC'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto BSR(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBD'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto BSR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBD'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a>
        constexpr auto BSWAP(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xC8'>>{};
        };
template <size_t a, uint8_t b>
        constexpr auto BT(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 4, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BT(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xA3'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a, uint8_t b>
        constexpr auto BT(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BT(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xA3'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };




template <size_t a, uint8_t b>
        constexpr auto BTC(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 7, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BTC(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBB'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a, uint8_t b>
        constexpr auto BTC(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BTC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBB'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };




template <size_t a, uint8_t b>
        constexpr auto BTR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 6, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BTR(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xB3'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a, uint8_t b>
        constexpr auto BTR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BTR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xB3'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };




template <size_t a, uint8_t b>
        constexpr auto BTS(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 5, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BTS(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xAB'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a, uint8_t b>
        constexpr auto BTS(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBA'>, modrm<3, 5, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto BTS(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xAB'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };




template <size_t a, size_t b, size_t c>
        constexpr auto BZHI(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF5'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };


template <size_t a>
        constexpr auto CALL(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xFF'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };

constexpr auto CBW() {
            return Instruction<Prefix<'\x66'>, Opcode<'\x98'>>{};
        };
constexpr auto CDQ() {
            return Instruction<Opcode<'\x99'>>{};
        };
constexpr auto CLC() {
            return Instruction<Opcode<'\xF8'>>{};
        };
constexpr auto CLD() {
            return Instruction<Opcode<'\xFC'>>{};
        };
constexpr auto CMC() {
            return Instruction<Opcode<'\xF5'>>{};
        };
template <size_t a, size_t b>
        constexpr auto CMOVA(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x47'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVA(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x47'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVAE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x43'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVAE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x43'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVB(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x42'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVB(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x42'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVBE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x46'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVBE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x46'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVC(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x42'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x42'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x44'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x44'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVG(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4F'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVG(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4F'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVGE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4D'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVGE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4D'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVL(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4C'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4C'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVLE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4E'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVLE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4E'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNA(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x46'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNA(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x46'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNAE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x42'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNAE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x42'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNB(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x43'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNB(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x43'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNBE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x47'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNBE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x47'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNC(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x43'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x43'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x45'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x45'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNG(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4E'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNG(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4E'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNGE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4C'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNGE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4C'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNL(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4D'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4D'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNLE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4F'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNLE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4F'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNO(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x41'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNO(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x41'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNP(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4B'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNP(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4B'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNS(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x49'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNS(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x49'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNZ(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x45'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVNZ(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x45'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVO(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x40'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVO(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x40'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVP(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4A'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVP(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4A'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVPE(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4A'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVPE(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4A'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVPO(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x4B'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVPO(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x4B'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVS(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x48'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVS(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x48'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVZ(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x44'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto CMOVZ(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x44'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto CMP(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 7, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto CMP(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x38'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto CMP(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 7, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto CMP(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 7, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto CMP(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x39'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto CMP(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto CMP(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto CMP(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x39'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };

















template <size_t a, size_t b>
        constexpr auto CMPXCHG(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xB0'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto CMPXCHG(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xB1'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto CMPXCHG(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xB1'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };








constexpr auto CPUID() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xA2'>>{};
        };
template <size_t a, size_t b>
        constexpr auto CRC32(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Prefix<'\xF2'>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<8, b>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto CRC32(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto CRC32(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Prefix<'\xF2'>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };















































constexpr auto CWD() {
            return Instruction<Prefix<'\x66'>, Opcode<'\x99'>>{};
        };
constexpr auto CWDE() {
            return Instruction<Opcode<'\x98'>>{};
        };
constexpr auto DAA() {
            return Instruction<Opcode<'\x27'>>{};
        };
constexpr auto DAS() {
            return Instruction<Opcode<'\x2F'>>{};
        };
template <size_t a>
        constexpr auto DEC(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xFE'>, modrm<3, 1, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto DEC(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x48'>>{};
        };
template <size_t a>
        constexpr auto DEC(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x48'>>{};
        };



template <size_t a>
        constexpr auto DIV(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 6, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto DIV(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 6, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto DIV(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };















constexpr auto EMMS() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x77'>>{};
        };




constexpr auto FEMMS() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x0E'>>{};
        };








template <size_t a>
        constexpr auto IDIV(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 7, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto IDIV(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 7, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto IDIV(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };



template <size_t a>
        constexpr auto IMUL(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 5, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto IMUL(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 5, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto IMUL(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 5, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto IMUL(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xAF'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto IMUL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xAF'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b, uint8_t c>
        constexpr auto IMUL(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>, Byte<c>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x6B'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>, to_string<1, Byte<c>>>{};
        };
template <size_t a, size_t b, uint16_t c>
        constexpr auto IMUL(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>, Word<c>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x69'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>, to_string<2, Word<c>>>{};
        };


template <size_t a, size_t b, uint8_t c>
        constexpr auto IMUL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, Byte<c>) {
            return Instruction<Opcode<'\x6B'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>, to_string<1, Byte<c>>>{};
        };
template <size_t a, size_t b, uint32_t c>
        constexpr auto IMUL(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, DWord<c>) {
            return Instruction<Opcode<'\x69'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>, to_string<4, DWord<c>>>{};
        };


template <size_t a>
        constexpr auto INC(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xFE'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto INC(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x40'>>{};
        };
template <size_t a>
        constexpr auto INC(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x40'>>{};
        };








template <uint8_t a>
        constexpr auto INT(Byte<a>) {
            return Instruction<Opcode<'\xCD'>, to_string<1, Byte<a>>>{};
        };
constexpr auto INTO() {
            return Instruction<Opcode<'\xCE'>>{};
        };
template <typename a>
        constexpr auto JA(Rel8<a>) {
            return Instruction<Opcode<'\x77'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JAE(Rel8<a>) {
            return Instruction<Opcode<'\x73'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JB(Rel8<a>) {
            return Instruction<Opcode<'\x72'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JBE(Rel8<a>) {
            return Instruction<Opcode<'\x76'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JC(Rel8<a>) {
            return Instruction<Opcode<'\x72'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JE(Rel8<a>) {
            return Instruction<Opcode<'\x74'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JECXZ(Rel8<a>) {
            return Instruction<Opcode<'\xE3'>, Rel8<a>>{};
        };
template <typename a>
        constexpr auto JG(Rel8<a>) {
            return Instruction<Opcode<'\x7F'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JGE(Rel8<a>) {
            return Instruction<Opcode<'\x7D'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JL(Rel8<a>) {
            return Instruction<Opcode<'\x7C'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JLE(Rel8<a>) {
            return Instruction<Opcode<'\x7E'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JMP(Rel8<a>) {
            return Instruction<Opcode<'\xEB'>, Rel8<a>>{};
        };

template <size_t a>
        constexpr auto JMP(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xFF'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };

template <typename a>
        constexpr auto JNA(Rel8<a>) {
            return Instruction<Opcode<'\x76'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNAE(Rel8<a>) {
            return Instruction<Opcode<'\x72'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNB(Rel8<a>) {
            return Instruction<Opcode<'\x73'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNBE(Rel8<a>) {
            return Instruction<Opcode<'\x77'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNC(Rel8<a>) {
            return Instruction<Opcode<'\x73'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNE(Rel8<a>) {
            return Instruction<Opcode<'\x75'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNG(Rel8<a>) {
            return Instruction<Opcode<'\x7E'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNGE(Rel8<a>) {
            return Instruction<Opcode<'\x7C'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNL(Rel8<a>) {
            return Instruction<Opcode<'\x7D'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNLE(Rel8<a>) {
            return Instruction<Opcode<'\x7F'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNO(Rel8<a>) {
            return Instruction<Opcode<'\x71'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNP(Rel8<a>) {
            return Instruction<Opcode<'\x7B'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNS(Rel8<a>) {
            return Instruction<Opcode<'\x79'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JNZ(Rel8<a>) {
            return Instruction<Opcode<'\x75'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JO(Rel8<a>) {
            return Instruction<Opcode<'\x70'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JP(Rel8<a>) {
            return Instruction<Opcode<'\x7A'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JPE(Rel8<a>) {
            return Instruction<Opcode<'\x7A'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JPO(Rel8<a>) {
            return Instruction<Opcode<'\x7B'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JS(Rel8<a>) {
            return Instruction<Opcode<'\x78'>, Rel8<a>>{};
        };

template <typename a>
        constexpr auto JZ(Rel8<a>) {
            return Instruction<Opcode<'\x74'>, Rel8<a>>{};
        };


































































constexpr auto LAHF() {
            return Instruction<Opcode<'\x9F'>>{};
        };




constexpr auto LFENCE() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xAE'>, Opcode<'\xE8'>>{};
        };
template <size_t a, size_t b>
        constexpr auto LZCNT(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBD'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto LZCNT(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Prefix<'\xF3'>, Opcode<'\x0F'>, Opcode<'\xBD'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };











constexpr auto MFENCE() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xAE'>, Opcode<'\xF0'>>{};
        };








template <size_t a, uint8_t b>
        constexpr auto MOV(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC6'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto MOV(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x88'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a, uint16_t b>
        constexpr auto MOV(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC7'>, modrm<3, 0, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto MOV(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x89'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint32_t b>
        constexpr auto MOV(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\xC7'>, modrm<3, 0, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto MOV(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x89'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };








































































template <size_t a, size_t b>
        constexpr auto MOVSX(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBE'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<8, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto MOVSX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBE'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<8, b>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto MOVSX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xBF'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };








template <size_t a, size_t b>
        constexpr auto MOVZX(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xB6'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<8, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto MOVZX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xB6'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<8, b>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto MOVZX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xB7'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };




template <size_t a>
        constexpr auto MUL(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 4, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto MUL(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 4, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto MUL(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };











template <size_t a, size_t b, size_t c>
        constexpr auto MULX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, c>{})>>{};
        };

template <size_t a>
        constexpr auto NEG(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 3, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto NEG(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 3, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto NEG(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 3, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };



constexpr auto NOP() {
            return Instruction<Opcode<'\x90'>>{};
        };
template <size_t a>
        constexpr auto NOT(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 2, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a>
        constexpr auto NOT(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 2, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto NOT(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };




template <size_t a, uint8_t b>
        constexpr auto OR(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 1, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto OR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x08'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto OR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 1, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto OR(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 1, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto OR(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x09'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto OR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 1, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto OR(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 1, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto OR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x09'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };



















































































constexpr auto PAUSE() {
            return Instruction<Prefix<'\xF3'>, Opcode<'\x90'>>{};
        };




















































template <size_t a, size_t b, size_t c>
        constexpr auto PDEP(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF5'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, c>{})>>{};
        };

template <size_t a, size_t b, size_t c>
        constexpr auto PEXT(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF5'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, c>{})>>{};
        };




















































































































































































template <size_t a>
        constexpr auto POP(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x58'>>{};
        };
template <size_t a>
        constexpr auto POP(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x58'>>{};
        };


template <size_t a, size_t b>
        constexpr auto POPCNT(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xB8'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto POPCNT(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Prefix<'\xF3'>, Opcode<'\x0F'>, Opcode<'\xB8'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

























































































































































template <uint8_t a>
        constexpr auto PUSH(Byte<a>) {
            return Instruction<Opcode<'\x6A'>, to_string<1, Byte<a>>>{};
        };
template <uint32_t a>
        constexpr auto PUSH(DWord<a>) {
            return Instruction<Opcode<'\x68'>, to_string<4, DWord<a>>>{};
        };
template <size_t a>
        constexpr auto PUSH(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x50'>>{};
        };
template <size_t a>
        constexpr auto PUSH(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x50'>>{};
        };







template <size_t a, uint8_t b>
        constexpr auto RCL(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 2, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto RCL(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 2, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto RCL(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 2, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };















template <size_t a, uint8_t b>
        constexpr auto RCR(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 3, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto RCR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 3, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto RCR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 3, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };










template <size_t a>
        constexpr auto RDRAND(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xC7'>, modrm<3, 6, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto RDRAND(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xC7'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };
template <size_t a>
        constexpr auto RDSEED(GeneralPurposeRegister<16, a>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xC7'>, modrm<3, 7, get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a>
        constexpr auto RDSEED(GeneralPurposeRegister<32, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xC7'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };
constexpr auto RDTSC() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x31'>>{};
        };
constexpr auto RDTSCP() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x01'>, Opcode<'\xF9'>>{};
        };
constexpr auto RET() {
            return Instruction<Opcode<'\xC3'>>{};
        };
template <uint16_t a>
        constexpr auto RET(Word<a>) {
            return Instruction<Opcode<'\xC2'>, to_string<2, Word<a>>>{};
        };

template <size_t a, uint8_t b>
        constexpr auto ROL(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ROL(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 0, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ROL(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 0, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };











template <size_t a, uint8_t b>
        constexpr auto ROR(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 1, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ROR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 1, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto ROR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 1, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };










template <size_t a, size_t b, uint8_t c>
        constexpr auto RORX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, Byte<c>) {
            return Instruction<Opcode<'\xF0'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>, to_string<1, Byte<c>>>{};
        };













constexpr auto SAHF() {
            return Instruction<Opcode<'\x9E'>>{};
        };

template <size_t a, uint8_t b>
        constexpr auto SAL(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 4, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SAL(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 4, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SAL(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };











template <size_t a, uint8_t b>
        constexpr auto SAR(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 7, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SAR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 7, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SAR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };










template <size_t a, size_t b, size_t c>
        constexpr auto SARX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SBB(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 3, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto SBB(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x18'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SBB(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 3, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto SBB(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 3, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto SBB(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x19'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SBB(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 3, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto SBB(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 3, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto SBB(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x19'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };









template <size_t a>
        constexpr auto SETA(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x97'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETAE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x93'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETB(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x92'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETBE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x96'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETC(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x92'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x94'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETG(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9F'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETGE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9D'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETL(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9C'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETLE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9E'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNA(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x96'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNAE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x92'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNB(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x93'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNBE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x97'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNC(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x93'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x95'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNG(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9E'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNGE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9C'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNL(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9D'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNLE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9F'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNO(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x91'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNP(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9B'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNS(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x99'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETNZ(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x95'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETO(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x90'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETP(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9A'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETPE(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9A'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETPO(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x9B'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETS(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x98'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a>
        constexpr auto SETZ(GeneralPurposeRegister<8, a>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x94'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

constexpr auto SFENCE() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xAE'>, Opcode<'\xF8'>>{};
        };















template <size_t a, uint8_t b>
        constexpr auto SHL(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 4, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SHL(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 4, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SHL(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };










template <size_t a, size_t b, uint8_t c>
        constexpr auto SHLD(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>, Byte<c>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xA4'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<c>>>{};
        };

template <size_t a, size_t b, uint8_t c>
        constexpr auto SHLD(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, Byte<c>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xA4'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<c>>>{};
        };





template <size_t a, size_t b, size_t c>
        constexpr auto SHLX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SHR(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xC0'>, modrm<3, 5, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SHR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xC1'>, modrm<3, 5, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SHR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\xC1'>, modrm<3, 5, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };










template <size_t a, size_t b, uint8_t c>
        constexpr auto SHRD(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>, Byte<c>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xAC'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<c>>>{};
        };

template <size_t a, size_t b, uint8_t c>
        constexpr auto SHRD(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, Byte<c>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xAC'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<c>>>{};
        };





template <size_t a, size_t b, size_t c>
        constexpr auto SHRX(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>, GeneralPurposeRegister<32, c>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };













constexpr auto STC() {
            return Instruction<Opcode<'\xF9'>>{};
        };
constexpr auto STD() {
            return Instruction<Opcode<'\xFD'>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SUB(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 5, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto SUB(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x28'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SUB(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 5, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto SUB(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 5, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto SUB(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x29'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto SUB(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 5, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto SUB(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 5, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto SUB(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x29'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };

















template <size_t a, size_t b>
        constexpr auto T1MSKC(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 7, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };




template <size_t a, uint8_t b>
        constexpr auto TEST(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\xF6'>, modrm<3, 0, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto TEST(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x84'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };

template <size_t a, uint16_t b>
        constexpr auto TEST(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\xF7'>, modrm<3, 0, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto TEST(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x85'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };

template <size_t a, uint32_t b>
        constexpr auto TEST(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\xF7'>, modrm<3, 0, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto TEST(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x85'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };






template <size_t a, size_t b>
        constexpr auto TZCNT(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xBC'>, modrm<3, get_reg(GeneralPurposeRegister<16, a>{}), get_reg(GeneralPurposeRegister<16, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto TZCNT(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Prefix<'\xF3'>, Opcode<'\x0F'>, Opcode<'\xBC'>, modrm<3, get_reg(GeneralPurposeRegister<32, a>{}), get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };

template <size_t a, size_t b>
        constexpr auto TZMSK(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x01'>, modrm<3, 4, get_reg(GeneralPurposeRegister<32, b>{})>>{};
        };







constexpr auto UD2() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x0B'>>{};
        };















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































constexpr auto VZEROALL() {
            return Instruction<Opcode<'\x77'>>{};
        };
constexpr auto VZEROUPPER() {
            return Instruction<Opcode<'\x77'>>{};
        };
template <size_t a, size_t b>
        constexpr auto XADD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xC0'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto XADD(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x0F'>, Opcode<'\xC1'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };
template <size_t a, size_t b>
        constexpr auto XADD(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x0F'>, Opcode<'\xC1'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto XCHG(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x86'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto XCHG(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x87'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };



template <size_t a, size_t b>
        constexpr auto XCHG(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x87'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };




constexpr auto XGETBV() {
            return Instruction<Opcode<'\x0F'>, Opcode<'\x01'>, Opcode<'\xD0'>>{};
        };
constexpr auto XLATB() {
            return Instruction<Opcode<'\xD7'>>{};
        };

template <size_t a, uint8_t b>
        constexpr auto XOR(GeneralPurposeRegister<8, a>, Byte<b>) {
            return Instruction<Opcode<'\x80'>, modrm<3, 6, get_reg(GeneralPurposeRegister<8, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto XOR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
            return Instruction<Opcode<'\x30'>, modrm<3, get_reg(GeneralPurposeRegister<8, b>{}), get_reg(GeneralPurposeRegister<8, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto XOR(GeneralPurposeRegister<16, a>, Byte<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x83'>, modrm<3, 6, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint16_t b>
        constexpr auto XOR(GeneralPurposeRegister<16, a>, Word<b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x81'>, modrm<3, 6, get_reg(GeneralPurposeRegister<16, a>{})>, to_string<2, Word<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto XOR(GeneralPurposeRegister<16, a>, GeneralPurposeRegister<16, b>) {
            return Instruction<Prefix<'\x66'>, Opcode<'\x31'>, modrm<3, get_reg(GeneralPurposeRegister<16, b>{}), get_reg(GeneralPurposeRegister<16, a>{})>>{};
        };


template <size_t a, uint8_t b>
        constexpr auto XOR(GeneralPurposeRegister<32, a>, Byte<b>) {
            return Instruction<Opcode<'\x83'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<1, Byte<b>>>{};
        };
template <size_t a, uint32_t b>
        constexpr auto XOR(GeneralPurposeRegister<32, a>, DWord<b>) {
            return Instruction<Opcode<'\x81'>, modrm<3, 6, get_reg(GeneralPurposeRegister<32, a>{})>, to_string<4, DWord<b>>>{};
        };
template <size_t a, size_t b>
        constexpr auto XOR(GeneralPurposeRegister<32, a>, GeneralPurposeRegister<32, b>) {
            return Instruction<Opcode<'\x31'>, modrm<3, get_reg(GeneralPurposeRegister<32, b>{}), get_reg(GeneralPurposeRegister<32, a>{})>>{};
        };












