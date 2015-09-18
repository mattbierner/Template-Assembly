### Stupid Template Tricks: Template Assembly

Uses C++ templates to embed x86 assembly code directly in normal C++ at compile-time using a domain specific language.

```cpp
// A simple loop with labels.
Asm<int>(
    MOV(ecx, 5_d),
    MOV(eax, 0_d),
"start"_label,
    CMP(ecx, 0_d),
    JE("done"_rel8),
    ADD(eax, 6_d),
    DEC(ecx),
    JMP("start"_rel8),
"done"_label,
    RET());
```

```cpp
// Accessing c++ args.
Asm<int>(
    MOV(eax, _[ebp - 0xc_b]),
    RET()
)(1, 2, 3); // 2

// Index memory addressing.
Asm<int>(
    MOV(ecx, 2_d),
    MOV(eax, _[ebp + 0x14_b + ecx * 2]),
    RET()
)(1, 2, 3); // 2
```

## About
This project uses C++ template metaprogramming to express simplified x86 assembly directly within C++. The actual "compilation" of the assembly happens at compiletime by constructing a static byte-string of machine code that can be invoked like a normal function.

By expressing assembly in C++ directly, we get type checking of instructions for free. We can also generate meaningful compiletime error messages for missing labels and other programmer errors within the assembly.

### Limitations
This project is for demonstration purposes and only supports a super limited subset of x86 assembly. Many instructions are currently not available and many assembly language features are missing or broken.


## Usage
`asm.h` includes all the files needed to write a basic program.

```cpp
#include "asm.h"
```

### Basics
`Asm` is the top level function that creates assembly code. This code acts like a functor with its implementation written in assembly language. `Asm` takes a single parmeter specifying the expected result type of the assembly code. 

```cpp
auto assembly_program = Asm<int>(
    MOV(eax, 4_d),
    RET());
    
assembly_program() == 4
```

The assembly directives are provided in the body of `Asm`. Instructions are in intel style syntax.

All the normal registers are available for use directly by name: `eax, esp, ...`. Immediate values are specified with user defined literals: `_b` for byte, `_w` for word, and `_d` for dword.

```cpp
Asm<int>(
    MOV(ecx, 4_d)
    MOV(eax, ecx)
)();
```

The size of the immediate must match the expected size of the operation (register size for example).

### Labels
You can also define labels and use labels with jump instructions.

```cpp
auto jump_program = Asm<int>(
    MOV(eax, 4_d),
    JMP("a"_rel8),
    ADD(eax, 2_d),
"a"_label,
    RET()); 

jump_program() == 4
```

It is a compile time error if you try to use a label that does not exist.


### Memory
A few of the x86 addressing modes are supported in a syntax that emulates normal assembly as much as reasonable:

```cpp
C++                       ASSEMBLY
_[eax]                    [eax]
_[4_b]                    [4]

_[eax + 4_b]              [eax + 4]

_[eax + ecx]              [eax + ecx]
_[eax + 4_b + ecx]        [eax + 4 + ecx]
_[eax + ecx * 2_b]        [eax + ecx * 2]
_[eax + 4_b + ecx * 2_b]  [eax + 4 + ecx * 2]
```

In general, `_` converts a register to a memory address with the `[]` operator. Memory addresses are overloaded to use the `+` operator for displacements. Multiplication creates a scaled index. All displacements and scales must use user defined literals (`_b`, `_w`, `_d`) instead of raw literals. 

### Macro-ish
Because the assembly is written directly in normal C++, you can use metaprogramming to construct simple assembly macros for instructions or groups of instructions:

```cpp
template <typename Count, typename... Body>
constexpr auto do_x_times(Count count, Body... body) {
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
```

```cpp
Asm<int>(
    MOV(eax, 0_d),
    do_x_times(5_d,
        ADD(eax, 6_d)),
    RET()
)();
```

Any C++ syntax can be used to extend the embedded language.


## Development

### Contribute
If you run into an issue or want a feature supported, feel free to create a pull request or open a bug.


### Generating Instruction Templates
`index.js` is the node script that generates the C++ x86 instruction template expressions found in `instr.h`. It's super hacky, but then again, what else can you expect from embedding C++ metaprogramming in Javascript string templates.

To regenerate the instruction file run:

```
$ node index.js
```

If you want to support a new instruction, take a look at modifying `index.js` to generate it in `instr.h`.