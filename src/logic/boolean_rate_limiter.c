#include "logic/boolean_rate_limiter.h"
#include <stdlib.h>

static int last_time = 0;

EVERYUTIL_API int boolean_rate_limiter(int input, int current_time, int rate_limit) {
    if (input && (current_time - last_time) >= rate_limit) {
        last_time = current_time;
        return 1;
    }
    return 0;
}