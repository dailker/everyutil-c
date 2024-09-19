#include "logic/evaluate_conditions.h"
#include <stdlib.h>

EVERYUTIL_API int evaluate_conditions(const int* conditions, size_t count, int require_all) { for (size_t i = 0; i < count; i++) { if (require_all && !conditions[i]) return 0; if (!require_all && conditions[i]) return 1; } return require_all; }