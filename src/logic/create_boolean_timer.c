#include "logic/create_boolean_timer.h"

static int timer = 0;

EVERYUTIL_API int create_boolean_timer(int input, int duration) {
    if (input) timer = duration;
    return timer > 0 ? (timer--, 1) : 0;
}