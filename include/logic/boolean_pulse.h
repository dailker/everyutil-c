#ifndef LOGIC_BOOLEAN_PULSE_H
#define LOGIC_BOOLEAN_PULSE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

typedef struct {
    int width;
    int period;
    int count;
} pulse_state_t;

/**
 * Creates a pulse state for generating boolean pulses.
 *
 * @param width Pulse width.
 * @param period Pulse period.
 * @return Pulse state structure.
 */
EVERYUTIL_API pulse_state_t boolean_pulse_create(int width, int period);

/**
 * Gets next pulse value.
 *
 * @param state Pulse state.
 * @return Next boolean pulse value.
 */
EVERYUTIL_API int boolean_pulse_next(pulse_state_t* state);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOLEAN_PULSE_H