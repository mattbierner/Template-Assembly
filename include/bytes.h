#pragma once

#include "encoding.h"
#include "immediate.h"
#include "instruction.h"
#include "memory.h"
#include "register.h"
#include "string.h"

namespace tasm {

template<typename CharT, CharT... chars>
constexpr auto operator ""_raw() {
    return instruction::Instruction<
        byte_string::to_bytes<byte_string::ByteString<chars...>>>{};
}

} // tasm
