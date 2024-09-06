#ifndef LOGIC_IS_RISING_SIGNAL_H
#define LOGIC_IS_RISING_SIGNAL_H

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

#include <stddef.h>

/**
 * Detects upward trend over a sliding window.
 *
 * @param array Array of boolean values.
 * @param size Size of array.
 * @param window Window size for trend detection.
 * @return 1 if rising signal detected, 0 otherwise.
 */
EVERYUTIL_API int is_rising_signal(const int* array, size_t size, int window);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IS_RISING_SIGNAL_H