#include "logic/assert_all_predicates.h"

EVERYUTIL_API int assert_all_predicates(int value, predicate_func* predicates, size_t count) { for (size_t i = 0; i < count; i++) if (!predicates[i](value)) return 0; return 1; }