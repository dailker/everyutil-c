#include "logic/boolean_pulse.h"

EVERYUTIL_API pulse_state_t boolean_pulse_create(int width, int period) {
    pulse_state_t state = {width, period, 0};
    return state;
}

EVERYUTIL_API int boolean_pulse_next(pulse_state_t* state) {
    if (!state) return 0;
    
    int on = (state->count % state->period) < state->width;
    state->count++;
    return on;
}