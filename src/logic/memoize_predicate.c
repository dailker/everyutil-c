#include "logic/memoize_predicate.h"

static int memo_input = -1;
static int memo_result = 0;

EVERYUTIL_API int memoize_predicate(int value, predicate_func predicate) {
    if (value != memo_input) {
        memo_input = value;
        memo_result = predicate(value);
    }
    return memo_result;
}