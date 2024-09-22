#include "logic/predicate_all.h"

EVERYUTIL_API int predicate_all(const int* values, size_t count, predicate_func predicate) { for (size_t i = 0; i < count; i++) if (!predicate(values[i])) return 0; return 1; }