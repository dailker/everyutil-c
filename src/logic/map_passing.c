#include "logic/map_passing.h"
#include <stdlib.h>

EVERYUTIL_API int map_passing(const int* values, size_t count, predicate_func predicate, int* result) { int result_count = 0; for (size_t i = 0; i < count; i++) { if (predicate(values[i])) result[result_count++] = values[i]; } return result_count; }