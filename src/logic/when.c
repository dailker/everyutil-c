#include "logic/when.h"

EVERYUTIL_API int when(int value, predicate_func predicate, transform_func transform) {
    return predicate(value) ? transform(value) : value;
}