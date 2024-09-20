#include "logic/invert_predicate.h"

EVERYUTIL_API int invert_predicate(int value, predicate_func predicate) { return !predicate(value); }