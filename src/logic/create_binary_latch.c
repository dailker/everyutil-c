#include "logic/create_binary_latch.h"
#include <stdlib.h>

static int latch_state = 0;

EVERYUTIL_API int create_binary_latch(int set, int reset) {
    if (set) latch_state = 1;
    if (reset) latch_state = 0;
    return latch_state;
}