#include "logic/bool_sustain.h"
#include <stdlib.h>

static int sustain_count = 0;

EVERYUTIL_API int bool_sustain(int input, int duration) {
    if (input) sustain_count = duration;
    return sustain_count > 0 ? (sustain_count--, 1) : 0;
}