#include "logic/boolean_by_pattern.h"
#include <stdlib.h>

EVERYUTIL_API int boolean_by_pattern(int index, const int* pattern, size_t pattern_size) { return pattern[index % pattern_size]; }