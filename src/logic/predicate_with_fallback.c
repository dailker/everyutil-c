#include "logic/predicate_with_fallback.h"
#include <stdlib.h>

EVERYUTIL_API int predicate_with_fallback(int value, predicate_func primary, predicate_func fallback) { return primary(value) || fallback(value); }