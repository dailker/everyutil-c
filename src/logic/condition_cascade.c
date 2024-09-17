#include "logic/condition_cascade.h"

EVERYUTIL_API int condition_cascade(int value, predicate_func* conditions, int* results, size_t count) { for (size_t i = 0; i < count; i++) if (conditions[i](value)) return results[i]; return 0; }