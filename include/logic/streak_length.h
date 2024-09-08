#ifndef LOGIC_STREAK_LENGTH_H
#define LOGIC_STREAK_LENGTH_H

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
 * Returns length of current streak from end of array.
 *
 * @param array Array of boolean values.
 * @param size Size of array.
 * @return Length of current streak.
 */
EVERYUTIL_API int streak_length(const int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_STREAK_LENGTH_H