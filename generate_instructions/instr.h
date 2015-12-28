#pragma once
#include "encoding.h"
#include "immediate.h"
#include "instruction.h"
#include "memory.h"
#include "register.h"
#include "string.h"
template <size_t a, int8_t b>
constexpr auto ADC(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<2, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADC(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x10'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADC(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x12'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADC(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<2, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto ADC(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<2, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADC(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x11'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADC(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x13'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADC(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<2, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto ADC(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<2, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x11'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADC(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x13'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADC(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<2, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto ADC(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<2, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x11'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADC(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x13'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADC(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<2, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADC(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x10'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADC(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<2, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto ADC(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<2, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADC(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x11'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADC(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<2, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto ADC(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<2, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADC(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x11'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADC(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<2, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto ADC(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<2, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADC(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x11'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto ADCX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADCX(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto ADCX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADCX(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADD(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<0, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADD(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x00'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADD(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x02'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADD(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<0, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto ADD(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<0, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADD(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x01'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADD(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x03'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADD(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<0, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto ADD(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<0, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADD(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x01'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADD(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x03'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto ADD(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<0, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto ADD(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<0, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto ADD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x01'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADD(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x03'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADD(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<0, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADD(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x00'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADD(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<0, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto ADD(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<0, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADD(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x01'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADD(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<0, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto ADD(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<0, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADD(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x01'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ADD(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<0, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto ADD(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<0, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto ADD(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x01'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto ADOX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADOX(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto ADOX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto ADOX(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto AND(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<4, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto AND(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x20'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto AND(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x22'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto AND(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<4, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto AND(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<4, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto AND(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x21'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto AND(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x23'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto AND(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<4, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto AND(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<4, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto AND(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x21'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto AND(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x23'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto AND(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<4, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto AND(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<4, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto AND(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x21'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto AND(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x23'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto AND(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<4, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto AND(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x20'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto AND(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<4, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto AND(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<4, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto AND(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x21'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto AND(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<4, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto AND(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<4, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto AND(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x21'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto AND(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<4, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto AND(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<4, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto AND(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x21'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto ANDN(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF2'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto ANDN(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>) {
    return Instruction<Opcode<'\xF2'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto ANDN(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF2'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto ANDN(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>) {
    return Instruction<Opcode<'\xF2'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>>::type>{};
}
template <size_t a, size_t b, int32_t c>
constexpr auto BEXTR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, dword<c>) {
    return Instruction<Opcode<'\x10'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, dword<c>>::type, to_bytes<dword<c>>>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto BEXTR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int32_t f>
constexpr auto BEXTR(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, dword<f>) {
    return Instruction<Opcode<'\x10'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, dword<f>>::type, to_bytes<dword<f>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto BEXTR(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>>::type>{};
}
template <size_t a, size_t b, int32_t c>
constexpr auto BEXTR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, dword<c>) {
    return Instruction<Opcode<'\x10'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, dword<c>>::type, to_bytes<dword<c>>>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto BEXTR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int32_t f>
constexpr auto BEXTR(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, dword<f>) {
    return Instruction<Opcode<'\x10'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, dword<f>>::type, to_bytes<dword<f>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto BEXTR(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCFILL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCFILL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCFILL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCFILL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCI(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x02'>, typename modrm<6, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x02'>, typename modrm<6, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCI(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x02'>, typename modrm<6, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x02'>, typename modrm<6, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCIC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<5, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCIC(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<5, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCIC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<5, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCIC(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<5, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCMSK(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x02'>, typename modrm<1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCMSK(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x02'>, typename modrm<1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCMSK(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x02'>, typename modrm<1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCMSK(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x02'>, typename modrm<1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCS(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<3, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCS(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<3, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLCS(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<3, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLCS(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<3, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSFILL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<2, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSFILL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<2, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSFILL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<2, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSFILL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<2, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSI(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<3, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<3, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSI(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<3, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<3, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSIC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<6, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSIC(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<6, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSIC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<6, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSIC(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<6, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSMSK(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<2, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSMSK(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<2, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSMSK(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<2, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSMSK(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<2, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSR(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BLSR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BLSR(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\xF3'>, typename modrm<1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BSF(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BSF(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BSF(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BSF(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BSF(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BSF(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BSR(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BSR(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BSR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BSR(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto BSR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto BSR(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a>
constexpr auto BSWAP(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, typename IntToBytes<1, 0xC8 + GeneralPurposeRegister<4, a>::index>::type>{};
}
template <size_t a>
constexpr auto BSWAP(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, typename IntToBytes<1, 0xC8 + GeneralPurposeRegister<8, a>::index>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BT(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<4, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BT(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xA3'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BT(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<4, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BT(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xA3'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BT(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<4, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BT(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xA3'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BT(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<4, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BT(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xA3'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BT(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<4, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BT(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xA3'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BT(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<4, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BT(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xA3'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTC(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<7, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTC(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xBB'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTC(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<7, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xBB'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTC(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<7, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xBB'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTC(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<7, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTC(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBB'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTC(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<7, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTC(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBB'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTC(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<7, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTC(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBB'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<6, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTR(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xB3'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<6, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xB3'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<6, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xB3'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<6, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTR(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB3'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<6, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTR(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB3'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<6, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTR(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB3'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTS(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<5, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTS(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xAB'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTS(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<5, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTS(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xAB'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto BTS(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<5, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto BTS(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xAB'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTS(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<5, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTS(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAB'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTS(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<5, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTS(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAB'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto BTS(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x0F'>, Opcode<'\xBA'>, typename modrm<5, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto BTS(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAB'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto BZHI(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto BZHI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto BZHI(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto BZHI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>>::type>{};
}
template <size_t a>
constexpr auto CALL(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xFF'>, typename modrm<2, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto CALL(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<2, Memory<8, a, b, c, d>>::type>{};
}
constexpr auto CBW() {
    return Instruction<Prefix<'\x66'>, Opcode<'\x98'>>{};
}
constexpr auto CDQ() {
    return Instruction<Opcode<'\x99'>>{};
}
constexpr auto CDQE() {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x98'>>{};
}
constexpr auto CLC() {
    return Instruction<Opcode<'\xF8'>>{};
}
constexpr auto CLD() {
    return Instruction<Opcode<'\xFC'>>{};
}
constexpr auto CMC() {
    return Instruction<Opcode<'\xF5'>>{};
}
template <size_t a, size_t b>
constexpr auto CMOVA(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVA(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVA(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVA(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVA(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVA(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVAE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVAE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVAE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVAE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVAE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVAE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVB(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVB(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVB(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVB(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVB(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVB(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVBE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVBE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVBE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVBE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVBE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVBE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVC(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVC(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVC(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVC(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVG(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVG(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVG(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVG(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVG(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVG(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVGE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVGE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVGE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVGE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVGE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVGE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVL(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVL(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVLE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVLE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVLE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVLE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVLE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVLE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNA(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNA(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNA(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNA(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNA(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNA(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x46'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNAE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNAE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNAE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNAE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNAE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNAE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x42'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNB(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNB(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNB(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNB(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNB(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNB(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNBE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNBE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNBE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNBE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNBE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNBE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x47'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNC(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNC(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNC(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNC(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x43'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNG(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNG(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNG(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNG(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNG(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNG(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4E'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNGE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNGE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNGE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNGE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNGE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNGE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNL(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNL(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNLE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNLE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNLE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNLE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNLE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNLE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4F'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNO(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x41'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNO(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x41'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNO(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x41'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNO(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x41'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNO(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x41'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNO(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x41'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNP(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNP(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNP(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNP(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNP(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNP(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNS(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x49'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNS(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x49'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNS(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x49'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNS(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x49'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNS(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x49'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNS(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x49'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNZ(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNZ(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNZ(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNZ(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVNZ(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVNZ(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x45'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVO(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x40'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVO(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x40'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVO(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x40'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVO(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x40'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVO(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x40'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVO(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x40'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVP(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVP(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVP(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVP(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVP(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVP(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVPE(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVPE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVPE(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVPE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVPE(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVPE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4A'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVPO(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVPO(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVPO(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVPO(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVPO(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVPO(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x4B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVS(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x48'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVS(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x48'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVS(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x48'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVS(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x48'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVS(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x48'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVS(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x48'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVZ(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVZ(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVZ(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVZ(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMOVZ(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMOVZ(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x44'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto CMP(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<7, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto CMP(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x38'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMP(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x3A'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto CMP(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<7, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto CMP(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<7, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto CMP(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x39'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMP(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x3B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto CMP(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<7, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto CMP(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<7, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto CMP(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x39'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMP(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x3B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto CMP(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<7, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto CMP(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<7, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto CMP(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x39'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CMP(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x3B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto CMP(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<7, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMP(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x38'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto CMP(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<7, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto CMP(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<7, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMP(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x39'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto CMP(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<7, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto CMP(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<7, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMP(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x39'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto CMP(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<7, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto CMP(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<7, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMP(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x39'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMPXCHG(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\xB0'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMPXCHG(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xB1'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMPXCHG(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xB1'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CMPXCHG(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xB1'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMPXCHG(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB0'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMPXCHG(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB1'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMPXCHG(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB1'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto CMPXCHG(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB1'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto CMPXCHG8B(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<1, Memory<8, a, b, c, d>>::type>{};
}
constexpr auto CPUID() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\xA2'>>{};
}
constexpr auto CQO() {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x99'>>{};
}
template <size_t a, size_t b>
constexpr auto CRC32(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<Prefix<'\xF2'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CRC32(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CRC32(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Prefix<'\xF2'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CRC32(GeneralPurposeRegister<4, a>, Memory<1, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CRC32(GeneralPurposeRegister<4, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CRC32(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CRC32(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<Prefix<'\xF2'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto CRC32(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Prefix<'\xF2'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CRC32(GeneralPurposeRegister<8, a>, Memory<1, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CRC32(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTSD2SI(GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTSD2SI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTSS2SI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTSS2SI(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTTSD2SI(GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTTSD2SI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF2'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTTSS2SI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto CVTTSS2SI(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
constexpr auto CWD() {
    return Instruction<Prefix<'\x66'>, Opcode<'\x99'>>{};
}
constexpr auto CWDE() {
    return Instruction<Opcode<'\x98'>>{};
}
template <size_t a>
constexpr auto DEC(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xFE'>, typename modrm<1, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto DEC(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xFF'>, typename modrm<1, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto DEC(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xFF'>, typename modrm<1, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto DEC(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xFF'>, typename modrm<1, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DEC(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFE'>, typename modrm<1, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DEC(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<1, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DEC(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<1, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DEC(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xFF'>, typename modrm<1, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto DIV(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<6, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto DIV(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<6, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto DIV(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<6, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto DIV(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<6, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DIV(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<6, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DIV(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<6, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DIV(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<6, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto DIV(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<6, Memory<8, a, b, c, d>>::type>{};
}
constexpr auto EMMS() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\x77'>>{};
}
constexpr auto FEMMS() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\x0E'>>{};
}
template <size_t a>
constexpr auto IDIV(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<7, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto IDIV(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<7, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto IDIV(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<7, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto IDIV(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<7, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IDIV(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<7, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IDIV(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<7, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IDIV(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<7, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IDIV(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<7, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto IMUL(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<5, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto IMUL(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<5, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto IMUL(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<5, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto IMUL(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<5, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IMUL(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<5, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IMUL(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<5, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IMUL(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<5, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto IMUL(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<5, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a, size_t b>
constexpr auto IMUL(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xAF'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto IMUL(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAF'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto IMUL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\xAF'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto IMUL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAF'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto IMUL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\xAF'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto IMUL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAF'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto IMUL(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, byte<c>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x6B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int16_t c>
constexpr auto IMUL(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, word<c>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x69'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, word<c>>::type, to_bytes<word<c>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int8_t f>
constexpr auto IMUL(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>, byte<f>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x6B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int16_t f>
constexpr auto IMUL(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>, word<f>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x69'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>, word<f>>::type, to_bytes<word<f>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto IMUL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x6B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int32_t c>
constexpr auto IMUL(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, dword<c>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x69'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, dword<c>>::type, to_bytes<dword<c>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int8_t f>
constexpr auto IMUL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, byte<f>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x6B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int32_t f>
constexpr auto IMUL(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, dword<f>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x69'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, dword<f>>::type, to_bytes<dword<f>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto IMUL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x6B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int32_t c>
constexpr auto IMUL(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, dword<c>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x69'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, dword<c>>::type, to_bytes<dword<c>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int8_t f>
constexpr auto IMUL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, byte<f>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x6B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int32_t f>
constexpr auto IMUL(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, dword<f>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x69'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, dword<f>>::type, to_bytes<dword<f>>>{};
}
template <size_t a>
constexpr auto INC(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xFE'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto INC(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xFF'>, typename modrm<0, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto INC(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xFF'>, typename modrm<0, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto INC(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xFF'>, typename modrm<0, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto INC(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFE'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto INC(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<0, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto INC(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<0, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto INC(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xFF'>, typename modrm<0, Memory<8, a, b, c, d>>::type>{};
}
template <int8_t a>
constexpr auto INT(byte<a>) {
    return Instruction<Opcode<'\xCD'>, to_bytes<byte<a>>>{};
}
template <typename a>
constexpr auto JA(Rel8<a>) {
    return Instruction<Opcode<'\x77'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JAE(Rel8<a>) {
    return Instruction<Opcode<'\x73'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JB(Rel8<a>) {
    return Instruction<Opcode<'\x72'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JBE(Rel8<a>) {
    return Instruction<Opcode<'\x76'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JC(Rel8<a>) {
    return Instruction<Opcode<'\x72'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JE(Rel8<a>) {
    return Instruction<Opcode<'\x74'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JECXZ(Rel8<a>) {
    return Instruction<Opcode<'\xE3'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JG(Rel8<a>) {
    return Instruction<Opcode<'\x7F'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JGE(Rel8<a>) {
    return Instruction<Opcode<'\x7D'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JL(Rel8<a>) {
    return Instruction<Opcode<'\x7C'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JLE(Rel8<a>) {
    return Instruction<Opcode<'\x7E'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JMP(Rel8<a>) {
    return Instruction<Opcode<'\xEB'>, Rel8<a>>{};
}
template <size_t a>
constexpr auto JMP(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xFF'>, typename modrm<4, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto JMP(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<4, Memory<8, a, b, c, d>>::type>{};
}
template <typename a>
constexpr auto JNA(Rel8<a>) {
    return Instruction<Opcode<'\x76'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNAE(Rel8<a>) {
    return Instruction<Opcode<'\x72'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNB(Rel8<a>) {
    return Instruction<Opcode<'\x73'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNBE(Rel8<a>) {
    return Instruction<Opcode<'\x77'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNC(Rel8<a>) {
    return Instruction<Opcode<'\x73'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNE(Rel8<a>) {
    return Instruction<Opcode<'\x75'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNG(Rel8<a>) {
    return Instruction<Opcode<'\x7E'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNGE(Rel8<a>) {
    return Instruction<Opcode<'\x7C'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNL(Rel8<a>) {
    return Instruction<Opcode<'\x7D'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNLE(Rel8<a>) {
    return Instruction<Opcode<'\x7F'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNO(Rel8<a>) {
    return Instruction<Opcode<'\x71'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNP(Rel8<a>) {
    return Instruction<Opcode<'\x7B'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNS(Rel8<a>) {
    return Instruction<Opcode<'\x79'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JNZ(Rel8<a>) {
    return Instruction<Opcode<'\x75'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JO(Rel8<a>) {
    return Instruction<Opcode<'\x70'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JP(Rel8<a>) {
    return Instruction<Opcode<'\x7A'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JPE(Rel8<a>) {
    return Instruction<Opcode<'\x7A'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JPO(Rel8<a>) {
    return Instruction<Opcode<'\x7B'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JRCXZ(Rel8<a>) {
    return Instruction<Opcode<'\xE3'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JS(Rel8<a>) {
    return Instruction<Opcode<'\x78'>, Rel8<a>>{};
}
template <typename a>
constexpr auto JZ(Rel8<a>) {
    return Instruction<Opcode<'\x74'>, Rel8<a>>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto LDMXCSR(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xAE'>, typename modrm<2, Memory<4, a, b, c, d>>::type>{};
}
constexpr auto LFENCE() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\xAE'>, Opcode<'\xE8'>>{};
}
template <size_t a, size_t b>
constexpr auto LZCNT(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto LZCNT(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto LZCNT(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto LZCNT(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto LZCNT(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto LZCNT(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBD'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
constexpr auto MFENCE() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\xAE'>, Opcode<'\xF0'>>{};
}
template <size_t a, int8_t b>
constexpr auto MOV(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC6'>, typename modrm<0, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto MOV(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x88'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOV(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x8A'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int16_t b>
constexpr auto MOV(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC7'>, typename modrm<0, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto MOV(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x89'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOV(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x8B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int32_t b>
constexpr auto MOV(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC7'>, typename modrm<0, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto MOV(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x89'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOV(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x8B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int32_t b>
constexpr auto MOV(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC7'>, typename modrm<0, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, int64_t b>
constexpr auto MOV(GeneralPurposeRegister<8, a>, qword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, typename IntToBytes<1, 0xB8 + GeneralPurposeRegister<8, a>::index>::type, to_bytes<qword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto MOV(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x89'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOV(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x8B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto MOV(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC6'>, typename modrm<0, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOV(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x88'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto MOV(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC7'>, typename modrm<0, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOV(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x89'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto MOV(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC7'>, typename modrm<0, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOV(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x89'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto MOV(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC7'>, typename modrm<0, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOV(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x89'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVBE(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVBE(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVBE(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOVBE(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOVBE(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOVBE(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\x38'>, Opcode<'\xF1'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOVNTI(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xC3'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto MOVNTI(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xC3'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVSX(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\xBE'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVSX(GeneralPurposeRegister<2, a>, Memory<1, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBE'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVSX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\xBE'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVSX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xBF'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVSX(GeneralPurposeRegister<4, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBE'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVSX(GeneralPurposeRegister<4, a>, Memory<2, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBF'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVSX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\xBE'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVSX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xBF'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVSX(GeneralPurposeRegister<8, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBE'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVSX(GeneralPurposeRegister<8, a>, Memory<2, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBF'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVSXD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x63'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVSXD(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x63'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVZX(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\xB6'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVZX(GeneralPurposeRegister<2, a>, Memory<1, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB6'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVZX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\xB6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVZX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xB7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVZX(GeneralPurposeRegister<4, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVZX(GeneralPurposeRegister<4, a>, Memory<2, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVZX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<1, b>{})>, Opcode<'\x0F'>, Opcode<'\xB6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto MOVZX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xB7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVZX(GeneralPurposeRegister<8, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto MOVZX(GeneralPurposeRegister<8, a>, Memory<2, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a>
constexpr auto MUL(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<4, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto MUL(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<4, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto MUL(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<4, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto MUL(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<4, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto MUL(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<4, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto MUL(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<4, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto MUL(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<4, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto MUL(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<4, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto MULX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto MULX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>) {
    return Instruction<Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto MULX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto MULX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>) {
    return Instruction<Opcode<'\xF6'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>>::type>{};
}
template <size_t a>
constexpr auto NEG(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<3, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto NEG(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<3, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto NEG(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<3, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto NEG(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<3, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NEG(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<3, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NEG(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<3, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NEG(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<3, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NEG(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<3, Memory<8, a, b, c, d>>::type>{};
}
constexpr auto NOP() {
    return Instruction<Opcode<'\x90'>>{};
}
template <size_t a>
constexpr auto NOT(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<2, GeneralPurposeRegister<1, a>>::type>{};
}
template <size_t a>
constexpr auto NOT(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<2, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto NOT(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<2, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto NOT(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<2, GeneralPurposeRegister<8, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NOT(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<2, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NOT(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<2, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NOT(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<2, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto NOT(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<2, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto OR(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<1, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto OR(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x08'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto OR(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x0A'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto OR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<1, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto OR(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<1, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto OR(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x09'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto OR(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto OR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<1, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto OR(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<1, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto OR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x09'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto OR(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto OR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<1, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto OR(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<1, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto OR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x09'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto OR(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto OR(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<1, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto OR(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x08'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto OR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<1, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto OR(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<1, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto OR(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x09'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto OR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<1, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto OR(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<1, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto OR(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x09'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto OR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<1, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto OR(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<1, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto OR(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x09'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
constexpr auto PAUSE() {
    return Instruction<Prefix<'\xF3'>, Opcode<'\x90'>>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto PDEP(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto PDEP(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto PDEP(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto PDEP(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto PEXT(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto PEXT(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, Memory<4, c, d, e, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto PEXT(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, size_t b, typename c, typename d, size_t e, Displacement f>
constexpr auto PEXT(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>) {
    return Instruction<Opcode<'\xF5'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, Memory<8, c, d, e, f>>::type>{};
}
template <size_t a>
constexpr auto POP(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, typename IntToBytes<1, 0x58 + GeneralPurposeRegister<2, a>::index>::type>{};
}
template <size_t a>
constexpr auto POP(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, typename IntToBytes<1, 0x58 + GeneralPurposeRegister<8, a>::index>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto POP(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x8F'>, typename modrm<0, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto POP(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x8F'>, typename modrm<0, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a, size_t b>
constexpr auto POPCNT(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xB8'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto POPCNT(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB8'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto POPCNT(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\xB8'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto POPCNT(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB8'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto POPCNT(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\xB8'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto POPCNT(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xB8'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PREFETCHNTA(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x18'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PREFETCHT0(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x18'>, typename modrm<1, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PREFETCHT1(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x18'>, typename modrm<2, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PREFETCHT2(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x18'>, typename modrm<3, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PREFETCHW(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x0D'>, typename modrm<1, Memory<1, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PREFETCHWT1(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x0D'>, typename modrm<2, Memory<1, a, b, c, d>>::type>{};
}
template <int8_t a>
constexpr auto PUSH(byte<a>) {
    return Instruction<Opcode<'\x6A'>, to_bytes<byte<a>>>{};
}
template <int32_t a>
constexpr auto PUSH(dword<a>) {
    return Instruction<Opcode<'\x68'>, to_bytes<dword<a>>>{};
}
template <size_t a>
constexpr auto PUSH(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, typename IntToBytes<1, 0x50 + GeneralPurposeRegister<2, a>::index>::type>{};
}
template <size_t a>
constexpr auto PUSH(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, typename IntToBytes<1, 0x50 + GeneralPurposeRegister<8, a>::index>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PUSH(Memory<2, a, b, c, d>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<6, Memory<2, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto PUSH(Memory<8, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xFF'>, typename modrm<6, Memory<8, a, b, c, d>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto RCL(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<2, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCL(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<2, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCL(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<2, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCL(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<2, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCL(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<2, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCL(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<2, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCL(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<2, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCL(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<2, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCR(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<3, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<3, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<3, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto RCR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<3, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCR(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<3, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<3, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<3, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto RCR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<3, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a>
constexpr auto RDRAND(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<6, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto RDRAND(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<6, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto RDRAND(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<6, GeneralPurposeRegister<8, a>>::type>{};
}
template <size_t a>
constexpr auto RDSEED(GeneralPurposeRegister<2, a>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<7, GeneralPurposeRegister<2, a>>::type>{};
}
template <size_t a>
constexpr auto RDSEED(GeneralPurposeRegister<4, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<7, GeneralPurposeRegister<4, a>>::type>{};
}
template <size_t a>
constexpr auto RDSEED(GeneralPurposeRegister<8, a>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xC7'>, typename modrm<7, GeneralPurposeRegister<8, a>>::type>{};
}
constexpr auto RDTSC() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\x31'>>{};
}
constexpr auto RDTSCP() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\x01'>, Opcode<'\xF9'>>{};
}
constexpr auto RET() {
    return Instruction<Opcode<'\xC3'>>{};
}
template <int16_t a>
constexpr auto RET(word<a>) {
    return Instruction<Opcode<'\xC2'>, to_bytes<word<a>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROL(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<0, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROL(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<0, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROL(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<0, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROL(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<0, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROL(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<0, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROL(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<0, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROL(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<0, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROL(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<0, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROR(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<1, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<1, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<1, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto ROR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<1, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROR(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<1, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<1, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<1, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto ROR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<1, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto RORX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>) {
    return Instruction<Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int8_t f>
constexpr auto RORX(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, byte<f>) {
    return Instruction<Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto RORX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>) {
    return Instruction<Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, int8_t f>
constexpr auto RORX(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, byte<f>) {
    return Instruction<Opcode<'\xF0'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAL(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<4, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAL(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<4, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAL(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<4, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAL(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<4, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAL(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<4, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAL(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<4, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAL(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<4, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAL(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<4, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAR(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<7, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<7, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<7, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SAR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<7, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAR(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<7, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<7, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<7, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SAR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<7, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto SARX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto SARX(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto SARX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto SARX(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SBB(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<3, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SBB(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x18'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SBB(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x1A'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SBB(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<3, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto SBB(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<3, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SBB(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x19'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SBB(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x1B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SBB(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<3, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto SBB(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<3, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SBB(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x19'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SBB(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x1B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SBB(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<3, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto SBB(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<3, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SBB(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x19'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SBB(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x1B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SBB(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<3, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SBB(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x18'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SBB(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<3, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto SBB(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<3, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SBB(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x19'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SBB(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<3, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto SBB(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<3, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SBB(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x19'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SBB(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<3, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto SBB(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<3, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SBB(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x19'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a>
constexpr auto SETA(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x97'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETA(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x97'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETAE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x93'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETAE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x93'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETB(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x92'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETB(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x92'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETBE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x96'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETBE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x96'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETC(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x92'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETC(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x92'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x94'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x94'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETG(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9F'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETG(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9F'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETGE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9D'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETGE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9D'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETL(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9C'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETL(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9C'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETLE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9E'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETLE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9E'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNA(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x96'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNA(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x96'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNAE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x92'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNAE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x92'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNB(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x93'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNB(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x93'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNBE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x97'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNBE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x97'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNC(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x93'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNC(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x93'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x95'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x95'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNG(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9E'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNG(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9E'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNGE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9C'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNGE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9C'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNL(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9D'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNL(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9D'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNLE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9F'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNLE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9F'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNO(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x91'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNO(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x91'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNP(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9B'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNP(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9B'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNS(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x99'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNS(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x99'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETNZ(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x95'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETNZ(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x95'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETO(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x90'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETO(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x90'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETP(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9A'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETP(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9A'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETPE(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9A'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETPE(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9A'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETPO(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x9B'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETPO(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x9B'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETS(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x98'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETS(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x98'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
template <size_t a>
constexpr auto SETZ(GeneralPurposeRegister<1, a>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\x94'>, typename modrm<0, GeneralPurposeRegister<1, a>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto SETZ(Memory<1, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\x94'>, typename modrm<0, Memory<1, a, b, c, d>>::type>{};
}
constexpr auto SFENCE() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\xAE'>, Opcode<'\xF8'>>{};
}
template <size_t a, int8_t b>
constexpr auto SHL(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<4, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SHL(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<4, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SHL(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<4, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SHL(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<4, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHL(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<4, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHL(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<4, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHL(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<4, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHL(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<4, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto SHLD(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, byte<c>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xA4'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto SHLD(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xA4'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto SHLD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xA4'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e, int8_t f>
constexpr auto SHLD(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>, byte<f>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xA4'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e, int8_t f>
constexpr auto SHLD(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>, byte<f>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xA4'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e, int8_t f>
constexpr auto SHLD(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>, byte<f>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xA4'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto SHLX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto SHLX(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto SHLX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto SHLX(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SHR(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xC0'>, typename modrm<5, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SHR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xC1'>, typename modrm<5, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SHR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xC1'>, typename modrm<5, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int8_t b>
constexpr auto SHR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xC1'>, typename modrm<5, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHR(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC0'>, typename modrm<5, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<5, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xC1'>, typename modrm<5, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SHR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xC1'>, typename modrm<5, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto SHRD(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, byte<c>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xAC'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto SHRD(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xAC'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <size_t a, size_t b, int8_t c>
constexpr auto SHRD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xAC'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, byte<c>>::type, to_bytes<byte<c>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e, int8_t f>
constexpr auto SHRD(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>, byte<f>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAC'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e, int8_t f>
constexpr auto SHRD(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>, byte<f>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAC'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e, int8_t f>
constexpr auto SHRD(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>, byte<f>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xAC'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>, byte<f>>::type, to_bytes<byte<f>>>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto SHRX(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>, GeneralPurposeRegister<4, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto SHRX(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>, GeneralPurposeRegister<4, f>>::type>{};
}
template <size_t a, size_t b, size_t c>
constexpr auto SHRX(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>, GeneralPurposeRegister<8, c>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e, size_t f>
constexpr auto SHRX(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>) {
    return Instruction<Opcode<'\xF7'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>, GeneralPurposeRegister<8, f>>::type>{};
}
constexpr auto STC() {
    return Instruction<Opcode<'\xF9'>>{};
}
constexpr auto STD() {
    return Instruction<Opcode<'\xFD'>>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto STMXCSR(Memory<4, a, b, c, d>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x0F'>, Opcode<'\xAE'>, typename modrm<3, Memory<4, a, b, c, d>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SUB(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<5, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SUB(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x28'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SUB(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x2A'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SUB(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<5, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto SUB(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<5, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SUB(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x29'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SUB(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x2B'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SUB(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<5, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto SUB(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<5, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SUB(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x29'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SUB(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x2B'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto SUB(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<5, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto SUB(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<5, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto SUB(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x29'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto SUB(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x2B'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SUB(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<5, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SUB(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x28'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SUB(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<5, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto SUB(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<5, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SUB(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x29'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SUB(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<5, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto SUB(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<5, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SUB(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x29'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto SUB(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<5, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto SUB(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<5, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto SUB(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x29'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto T1MSKC(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<7, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto T1MSKC(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<7, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto T1MSKC(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<7, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto T1MSKC(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<7, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto TEST(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\xF6'>, typename modrm<0, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto TEST(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x84'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, int16_t b>
constexpr auto TEST(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\xF7'>, typename modrm<0, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto TEST(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x85'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, int32_t b>
constexpr auto TEST(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\xF7'>, typename modrm<0, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto TEST(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x85'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, int32_t b>
constexpr auto TEST(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\xF7'>, typename modrm<0, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto TEST(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x85'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto TEST(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF6'>, typename modrm<0, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto TEST(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x84'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto TEST(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<0, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto TEST(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x85'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto TEST(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\xF7'>, typename modrm<0, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto TEST(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x85'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto TEST(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\xF7'>, typename modrm<0, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto TEST(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x85'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto TZCNT(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,get_rex_b(GeneralPurposeRegister<2, b>{})>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto TZCNT(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto TZCNT(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,get_rex_b(GeneralPurposeRegister<4, b>{})>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto TZCNT(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto TZCNT(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,get_rex_b(GeneralPurposeRegister<8, b>{})>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto TZCNT(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Prefix<'\xF3'>, make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xBC'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto TZMSK(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<4, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto TZMSK(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<4, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto TZMSK(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<Opcode<'\x01'>, typename modrm<4, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto TZMSK(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x01'>, typename modrm<4, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
constexpr auto UD2() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\x0B'>>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSD2SI(GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSD2SI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSD2USI(GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x79'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSD2USI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x79'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSS2SI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSS2SI(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x2D'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSS2USI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x79'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTSS2USI(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x79'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSD2SI(GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSD2SI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSD2USI(GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x78'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSD2USI(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<Opcode<'\x78'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSS2SI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSS2SI(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x2C'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSS2USI(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x78'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto VCVTTSS2USI(GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>) {
    return Instruction<Opcode<'\x78'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<4, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto VLDMXCSR(Memory<4, a, b, c, d>) {
    return Instruction<Opcode<'\xAE'>, typename modrm<2, Memory<4, a, b, c, d>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d>
constexpr auto VSTMXCSR(Memory<4, a, b, c, d>) {
    return Instruction<Opcode<'\xAE'>, typename modrm<3, Memory<4, a, b, c, d>>::type>{};
}
constexpr auto VZEROALL() {
    return Instruction<Opcode<'\x77'>>{};
}
constexpr auto VZEROUPPER() {
    return Instruction<Opcode<'\x77'>>{};
}
template <size_t a, size_t b>
constexpr auto XADD(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x0F'>, Opcode<'\xC0'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XADD(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x0F'>, Opcode<'\xC1'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XADD(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x0F'>, Opcode<'\xC1'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XADD(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x0F'>, Opcode<'\xC1'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XADD(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xC0'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XADD(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xC1'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XADD(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xC1'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XADD(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x0F'>, Opcode<'\xC1'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XCHG(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x86'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XCHG(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x86'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XCHG(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x87'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XCHG(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x87'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XCHG(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x87'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XCHG(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x87'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, size_t b>
constexpr auto XCHG(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x87'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XCHG(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x87'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XCHG(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x86'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XCHG(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x87'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XCHG(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x87'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XCHG(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x87'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}
constexpr auto XGETBV() {
    return Instruction<Opcode<'\x0F'>, Opcode<'\x01'>, Opcode<'\xD0'>>{};
}
constexpr auto XLATB() {
    return Instruction<Opcode<'\xD7'>>{};
}
template <size_t a, int8_t b>
constexpr auto XOR(GeneralPurposeRegister<1, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x80'>, typename modrm<6, GeneralPurposeRegister<1, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, size_t b>
constexpr auto XOR(GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, b>{}),0,get_rex_b(GeneralPurposeRegister<1, a>{})>, Opcode<'\x30'>, typename modrm<-1, GeneralPurposeRegister<1, a>, GeneralPurposeRegister<1, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XOR(GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, a>{}),0,0>, Opcode<'\x32'>, typename modrm<-1, GeneralPurposeRegister<1, a>, Memory<1, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto XOR(GeneralPurposeRegister<2, a>, byte<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x83'>, typename modrm<6, GeneralPurposeRegister<2, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int16_t b>
constexpr auto XOR(GeneralPurposeRegister<2, a>, word<b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x81'>, typename modrm<6, GeneralPurposeRegister<2, a>, word<b>>::type, to_bytes<word<b>>>{};
}
template <size_t a, size_t b>
constexpr auto XOR(GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, b>{}),0,get_rex_b(GeneralPurposeRegister<2, a>{})>, Opcode<'\x31'>, typename modrm<-1, GeneralPurposeRegister<2, a>, GeneralPurposeRegister<2, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XOR(GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, a>{}),0,0>, Opcode<'\x33'>, typename modrm<-1, GeneralPurposeRegister<2, a>, Memory<2, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto XOR(GeneralPurposeRegister<4, a>, byte<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x83'>, typename modrm<6, GeneralPurposeRegister<4, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto XOR(GeneralPurposeRegister<4, a>, dword<b>) {
    return Instruction<make_rex<0,0,0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x81'>, typename modrm<6, GeneralPurposeRegister<4, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto XOR(GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, b>{}),0,get_rex_b(GeneralPurposeRegister<4, a>{})>, Opcode<'\x31'>, typename modrm<-1, GeneralPurposeRegister<4, a>, GeneralPurposeRegister<4, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XOR(GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, a>{}),0,0>, Opcode<'\x33'>, typename modrm<-1, GeneralPurposeRegister<4, a>, Memory<4, b, c, d, e>>::type>{};
}
template <size_t a, int8_t b>
constexpr auto XOR(GeneralPurposeRegister<8, a>, byte<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x83'>, typename modrm<6, GeneralPurposeRegister<8, a>, byte<b>>::type, to_bytes<byte<b>>>{};
}
template <size_t a, int32_t b>
constexpr auto XOR(GeneralPurposeRegister<8, a>, dword<b>) {
    return Instruction<make_rex<1,0,0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x81'>, typename modrm<6, GeneralPurposeRegister<8, a>, dword<b>>::type, to_bytes<dword<b>>>{};
}
template <size_t a, size_t b>
constexpr auto XOR(GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, b>{}),0,get_rex_b(GeneralPurposeRegister<8, a>{})>, Opcode<'\x31'>, typename modrm<-1, GeneralPurposeRegister<8, a>, GeneralPurposeRegister<8, b>>::type>{};
}
template <size_t a, typename b, typename c, size_t d, Displacement e>
constexpr auto XOR(GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, a>{}),0,0>, Opcode<'\x33'>, typename modrm<-1, GeneralPurposeRegister<8, a>, Memory<8, b, c, d, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto XOR(Memory<1, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x80'>, typename modrm<6, Memory<1, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XOR(Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<1, e>{}),0,0>, Opcode<'\x30'>, typename modrm<-1, Memory<1, a, b, c, d>, GeneralPurposeRegister<1, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto XOR(Memory<2, a, b, c, d>, byte<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<6, Memory<2, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int16_t e>
constexpr auto XOR(Memory<2, a, b, c, d>, word<e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<6, Memory<2, a, b, c, d>, word<e>>::type, to_bytes<word<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XOR(Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>) {
    return Instruction<Prefix<'\x66'>, make_rex<0,get_rex_r(GeneralPurposeRegister<2, e>{}),0,0>, Opcode<'\x31'>, typename modrm<-1, Memory<2, a, b, c, d>, GeneralPurposeRegister<2, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto XOR(Memory<4, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x83'>, typename modrm<6, Memory<4, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto XOR(Memory<4, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<0,0,0,0>, Opcode<'\x81'>, typename modrm<6, Memory<4, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XOR(Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>) {
    return Instruction<make_rex<0,get_rex_r(GeneralPurposeRegister<4, e>{}),0,0>, Opcode<'\x31'>, typename modrm<-1, Memory<4, a, b, c, d>, GeneralPurposeRegister<4, e>>::type>{};
}
template <typename a, typename b, size_t c, Displacement d, int8_t e>
constexpr auto XOR(Memory<8, a, b, c, d>, byte<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x83'>, typename modrm<6, Memory<8, a, b, c, d>, byte<e>>::type, to_bytes<byte<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, int32_t e>
constexpr auto XOR(Memory<8, a, b, c, d>, dword<e>) {
    return Instruction<make_rex<1,0,0,0>, Opcode<'\x81'>, typename modrm<6, Memory<8, a, b, c, d>, dword<e>>::type, to_bytes<dword<e>>>{};
}
template <typename a, typename b, size_t c, Displacement d, size_t e>
constexpr auto XOR(Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>) {
    return Instruction<make_rex<1,get_rex_r(GeneralPurposeRegister<8, e>{}),0,0>, Opcode<'\x31'>, typename modrm<-1, Memory<8, a, b, c, d>, GeneralPurposeRegister<8, e>>::type>{};
}