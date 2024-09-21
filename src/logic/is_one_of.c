#include "logic/is_one_of.h"

EVERYUTIL_API int is_one_of(int value, const int* values, size_t count) { for (size_t i = 0; i < count; i++) if (values[i] == value) return 1; return 0; }