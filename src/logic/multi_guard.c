#include "logic/multi_guard.h"

EVERYUTIL_API int multi_guard(int value, predicate_func* guards, size_t count) { for (size_t i = 0; i < count; i++) if (!guards[i](value)) return 0; return value; }