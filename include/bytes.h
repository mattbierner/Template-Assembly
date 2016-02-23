#pragma once

#include "instruction.h"
#include "register.h"

namespace tasm {

template <typename CharT, CharT... chars>
constexpr auto operator ""_raw() {
    return instruction::Instruction<
        byte_string::to_bytes<byte_string::ByteString<chars...>>>{};
}

} // tasm
