#include "logic/predicate_some.h"

EVERYUTIL_API int predicate_some(const int* values, size_t count, predicate_func predicate) { for (size_t i = 0; i < count; i++) if (predicate(values[i])) return 1; return 0; }