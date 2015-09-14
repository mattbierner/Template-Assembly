#pragma once

#include "symbol_table.h"

/**
    Base assembler state object.
*/
template <template <size_t, typename> class self, size_t ic, typename _labels>
struct BaseState {
    /**
        Location of current instruction.
    */
    static constexpr size_t index = ic;
    
    /**
        List of valid labels in the program.
    */
    using labels = _labels;
    
    /**
        Increment the instruction counter by `x`.
    */
    template <size_t x>
    using inc = self<index + x, labels>;
    
    /**
        Register a new label at the current index
    */
    template <typename newLabel>
    using add_label = self<index, cons<
        SymbolTableEntry<newLabel, Offset<index>>,
        labels>>;
};

/**
    State used for pass one of the assembler.
    
    Always looks up something in the label table.
*/
template <size_t lc, typename _labels>
struct Pass1State : BaseState<Pass1State, lc, _labels> {
    template <typename name>
    using lookup_label = symbol_table_lookup<None, name, _labels>;
};

/**
    Initial state for pass1
*/
using pass1state = Pass1State<0, empty_symbol_table>;


/**
    Undefined instruction that signals that an undefined label was used in pass2.
*/
template <typename label>
struct no_such_label;

/**
    State used for pass two of the assembler.
    
    By now the symbol table should be complete so any undefined symbols are treated
    as errors.
*/
template <size_t lc, typename _labels>
struct Pass2State : BaseState<Pass2State, lc, _labels> {
    template <typename name>
    using lookup_label = symbol_table_lookup<no_such_label<name>, name, _labels>;
};

/**
    Create a pass2 state from a pass1 state.
*/
template <typename pass1state>
using pass2state = Pass2State<0, typename pass1state::labels>;
