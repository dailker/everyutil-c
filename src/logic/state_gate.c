#include "logic/state_gate.h"

static int state = 0;

EVERYUTIL_API int state_gate(int input, int enable) {
    if (enable) state = input;
    return state;
}