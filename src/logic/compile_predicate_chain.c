#include "logic/compile_predicate_chain.h"

EVERYUTIL_API int compile_predicate_chain(int value, predicate_func* predicates, size_t count) { for (size_t i = 0; i < count; i++) if (!predicates[i](value)) return 0; return 1; }