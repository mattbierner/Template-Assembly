#pragma once

#include "label.h"
#include "symbol_table.h"

namespace tasm { namespace state {

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
};

/**
    State used for pass one of the assembler.
    
    Always looks up something in the label table.
*/
template <size_t lc, typename _labels>
struct Pass1State : BaseState<Pass1State, lc, _labels> {
    template <typename name>
    using lookup_label = symbol_table::symbol_table_lookup<details::None, name, _labels>;
    
    /**
        Register a new label at the current index
    */
    template <typename newLabel>
    using add_label = Pass1State<lc, symbol_table::symbol_table_add<newLabel, details::LabelOffset<lc>, _labels>>;
};

/**
    Initial state for pass1
*/
using pass1state = Pass1State<0, symbol_table::empty_symbol_table>;


/**
    Undefined struct that signals that an undefined label was used in pass2.
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
    using lookup_label = symbol_table::symbol_table_lookup<no_such_label<name>, name, _labels>;
    
    /**
        Register a new label at the current index. Noop in pass 2.
    */
    template <typename newLabel>
    using add_label = Pass2State<lc, _labels>;
};

/**
    Create a pass2 state from a pass1 state.
*/
template <typename pass1state>
using pass2state = Pass2State<0, typename pass1state::labels>;

}} // tasm::state
