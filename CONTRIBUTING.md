# Contributing

## Running Tests
Please make sure to run the tests (and hopefully add some new ones) before submitting a pull request. The tests use [Catch.hpp](catch) and are built using cmake:

```bash
$ mkdir build; cd build
$ cmake ..
$ make
$ ./tester
```

## Generating Instructions
The C++ x86 instruction template expression are generated using a simple Node script: `generate_instructions/generate.js`. It's super hacky, but then again, what else can you expect from embedding C++ metaprogramming in Javascript string templates.

To regenerate the instruction:

```bash
$ npm install
$ npm run generate
```

The instructions are written to: `instructions-set/instr.h` by default.


[catch]: https://github.com/philsquared/Catch
