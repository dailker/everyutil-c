#include "logic/debounced_predicate.h"

static int last_result = 0;
static int debounce_count = 0;

EVERYUTIL_API int debounced_predicate(int value, predicate_func predicate, int threshold) {
    int result = predicate(value);
    if (result == last_result) debounce_count++;
    else debounce_count = 0;
    last_result = result;
    return debounce_count >= threshold ? result : 0;
}