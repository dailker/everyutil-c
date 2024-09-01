#ifndef LOGIC_BOOL_FLIPS_H
#define LOGIC_BOOL_FLIPS_H

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
 * Counts how many times boolean array switches value.
 *
 * @param array Array of boolean values.
 * @param size Size of array.
 * @return Number of flips.
 */
EVERYUTIL_API int bool_flips(const int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOL_FLIPS_H