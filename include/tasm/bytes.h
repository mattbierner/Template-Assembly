#pragma once

#include <tasm/private/instruction.h>
#include <tasm/private/register.h>

namespace tasm {

template <typename CharT, CharT... chars>
constexpr auto operator ""_raw() {
    return instruction::Instruction<
        byte_string::to_bytes<byte_string::ByteString<chars...>>>{};
}

} // tasm
