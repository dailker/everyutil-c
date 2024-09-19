#include "logic/group_by_predicate.h"
#include <stdlib.h>

EVERYUTIL_API int group_by_predicate(const int* values, size_t count, predicate_func predicate, int* true_group, int* false_group) { int true_count = 0, false_count = 0; for (size_t i = 0; i < count; i++) { if (predicate(values[i])) true_group[true_count++] = values[i]; else false_group[false_count++] = values[i]; } return true_count; }