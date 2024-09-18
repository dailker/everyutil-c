#include "logic/cycle_predicates.h"

static int cycle_idx = 0;

EVERYUTIL_API int cycle_predicates(int value, predicate_func* predicates, size_t count) {
    int result = predicates[cycle_idx](value);
    cycle_idx = (cycle_idx + 1) % count;
    return result;
}