#include "logic/conditional_chain.h"

EVERYUTIL_API int conditional_chain(int value, predicate_func condition, transform_func transform) { return condition(value) ? transform(value) : value; }