#include "logic/prioritized_predicates.h"

EVERYUTIL_API int prioritized_predicates(int value, predicate_func* predicates, const int* priorities, size_t count) { int max_priority = -1; int result = 0; for (size_t i = 0; i < count; i++) { if (predicates[i](value) && priorities[i] > max_priority) { max_priority = priorities[i]; result = 1; } } return result; }