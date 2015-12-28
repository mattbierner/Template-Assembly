#pragma once

#include "encoding.h"
#include "immediate.h"
#include "instruction.h"
#include "memory.h"
#include "register.h"
#include "string.h"

template<typename CharT, CharT... chars>
constexpr auto operator ""_raw() {
    return Instruction<to_bytes<ByteString<chars...>>>{};
}
