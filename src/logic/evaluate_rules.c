#include "logic/evaluate_rules.h"
#include <stdlib.h>

EVERYUTIL_API int evaluate_rules(int input, const int* rules, size_t count) { for (size_t i = 0; i < count; i++) { if (input == rules[i]) return 1; } return 0; }