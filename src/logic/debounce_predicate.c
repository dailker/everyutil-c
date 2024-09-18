#include "logic/debounce_predicate.h"
#include <stdlib.h>

static int last_result = 0;
static int count = 0;

EVERYUTIL_API int debounce_predicate(int value, predicate_func predicate, int threshold) {
    int result = predicate(value);
    if (result == last_result) count++;
    else count = 0;
    last_result = result;
    return count >= threshold ? result : 0;
}