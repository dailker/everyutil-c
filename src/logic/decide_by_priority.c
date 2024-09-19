#include "logic/decide_by_priority.h"
#include <stdlib.h>

EVERYUTIL_API int decide_by_priority(const int* values, const int* priorities, size_t count) { int max_priority = -1; int result = 0; for (size_t i = 0; i < count; i++) { if (values[i] && priorities[i] > max_priority) { max_priority = priorities[i]; result = values[i]; } } return result; }