#include "logic/benchmark_predicate.h"

EVERYUTIL_API int benchmark_predicate(int value, predicate_func predicate) { return predicate(value); }