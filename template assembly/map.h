#pragma once

#include "list.h"

template <typename k, typename v>
struct MapPair {};

template <typename... elements>
using Map = List<elements...>;


/**
*/
template <typename key, typename map>
struct MapLookup {
    using type = typename MapLookup<key, cdr<map>>::type;
};

template <typename key, typename value, typename... xs>
struct MapLookup<key, Map<MapPair<key, value>, xs...>> {
    using type = value;
};

template <typename key>
struct MapLookup<key, Map<>> {
    static_assert(sizeof(key) == -1, "No such key");
};

template <typename key, typename map>
using map_lookup = typename MapLookup<key, map>::type;


template <typename def, typename key, typename map>
struct MapLookupDef {
    using type = typename MapLookupDef<def, key, cdr<map>>::type;
};

template <typename def, typename key, typename value, typename... xs>
struct MapLookupDef<def, key, Map<MapPair<key, value>, xs...>> {
    using type = value;
};

template <typename def, typename key>
struct MapLookupDef<def, key, Map<>> {
    using type = call<def, None>;
};

