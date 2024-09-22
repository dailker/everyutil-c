#include "logic/none_pass.h"

EVERYUTIL_API int none_pass(int value, predicate_func* predicates, size_t count) { for (size_t i = 0; i < count; i++) if (predicates[i](value)) return 0; return 1; }