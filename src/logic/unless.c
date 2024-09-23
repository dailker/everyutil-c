#include "logic/unless.h"

EVERYUTIL_API int unless(int value, predicate_func predicate, transform_func transform) {
    return !predicate(value) ? transform(value) : value;
}