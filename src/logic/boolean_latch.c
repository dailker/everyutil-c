#include "logic/boolean_latch.h"
#include <stdlib.h>

static int latch = 0;

EVERYUTIL_API int boolean_latch(int set, int reset) {
    if (set) latch = 1;
    if (reset) latch = 0;
    return latch;
}