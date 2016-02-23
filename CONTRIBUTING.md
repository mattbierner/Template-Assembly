# Contributing

## Running Tests
A cmake script is included to build tests. Just do:

``` bash
$ mkdir build; cd build
$ cmake ..
$ make
$ ./tester
```

## Generating Instruction Templates
`index.js` is the node script that generates the C++ x86 instruction template expressions found in `instr.h`. It's super hacky, but then again, what else can you expect from embedding C++ metaprogramming in Javascript string templates.

To regenerate the instruction file run:

``` bash
$ node index.js
```

If you want to support a new instruction, take a look at modifying `index.js` to generate it in `instr.h`.
