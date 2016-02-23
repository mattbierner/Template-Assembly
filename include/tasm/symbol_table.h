/**
    A super basic symbol table implementation.
*/
#pragma once

#include <tasm/list.h>

namespace tasm { namespace symbol_table {

template <typename k, typename v>
struct SymbolTableEntry {};

/**
    Maps symbol names to symbol data.
    
    Does not take location into account at all, so you probably should only
    define a symbol one in a given program.
*/
template <typename... elements>
using SymbolTable = list::List<elements...>;

using empty_symbol_table = list::List<>;

/**
    Try to lookup a value in the symbol table or return `def` if not found.
*/
template <typename def, typename key, typename map>
struct SymbolTableLookup {
    using type = typename SymbolTableLookup<def, key, list::cdr<map>>::type;
};

template <typename def, typename key, typename value, typename... xs>
struct SymbolTableLookup<def, key, SymbolTable<SymbolTableEntry<key, value>, xs...>> {
    using type = value;
};

template <typename def, typename key>
struct SymbolTableLookup<def, key, empty_symbol_table> {
    using type = def;
};

template <typename def, typename key, typename map>
using symbol_table_lookup = typename SymbolTableLookup<def, key, map>::type;

template <typename name>
struct duplicate_symbols_not_allowed;

/**
    Add an entry to the symbol table.
*/
template <typename key, typename value, typename table>
using symbol_table_add = typename std::conditional_t<
    std::is_same<
        details::None,
        symbol_table_lookup<details::None, key, table>>::value,
    details::identity<list::cons<SymbolTableEntry<key, value>, table>>,
    duplicate_symbols_not_allowed<key>>::type;
    
}} // tasm::symbol_table
