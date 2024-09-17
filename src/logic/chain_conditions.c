#include "logic/chain_conditions.h"

EVERYUTIL_API int chain_conditions(int input, predicate_func* predicates, size_t count) { int result = input; for (size_t i = 0; i < count; i++) if (!predicates[i](result)) return 0; return 1; }