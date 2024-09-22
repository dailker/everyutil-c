#include "logic/match_pattern.h"
#include <stdlib.h>

EVERYUTIL_API int match_pattern(const int* input, const int* pattern, size_t size) { for (size_t i = 0; i < size; i++) { if (input[i] != pattern[i]) return 0; } return 1; }