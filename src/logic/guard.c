#include "logic/guard.h"

EVERYUTIL_API int guard(int value, predicate_func predicate) { return predicate(value) ? value : 0; }