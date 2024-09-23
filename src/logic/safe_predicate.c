#include "logic/safe_predicate.h"

EVERYUTIL_API int safe_predicate(int value, predicate_func predicate) { return predicate ? predicate(value) : 0; }