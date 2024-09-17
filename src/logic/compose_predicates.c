#include "logic/compose_predicates.h"

EVERYUTIL_API int compose_predicates(int value, predicate_func pred1, predicate_func pred2) { return pred1(value) && pred2(value); }