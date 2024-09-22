#include "logic/negate.h"

EVERYUTIL_API int negate(int value, predicate_func predicate) {
    return !predicate(value);
}