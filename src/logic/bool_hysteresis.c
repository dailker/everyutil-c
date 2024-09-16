#include "logic/bool_hysteresis.h"
#include <stdlib.h>

static int state = 0;

EVERYUTIL_API int bool_hysteresis(int input, int high_thresh, int low_thresh) {
    if (input >= high_thresh) state = 1;
    else if (input <= low_thresh) state = 0;
    return state;
}