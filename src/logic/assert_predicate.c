#include "logic/assert_predicate.h"
#include <stdlib.h>

EVERYUTIL_API int assert_predicate(int value, predicate_func predicate) { return predicate(value) ? value : 0; }