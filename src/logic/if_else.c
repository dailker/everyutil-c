#include "logic/if_else.h"

EVERYUTIL_API int if_else(int value, predicate_func predicate, transform_func if_fn, transform_func else_fn) {
    return predicate(value) ? if_fn(value) : else_fn(value);
}