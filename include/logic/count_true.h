#ifndef LOGIC_COUNT_TRUE_H
#define LOGIC_COUNT_TRUE_H

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
 * Count number of true values in boolean array.
 *
 * @param array Array of integers (0=false, non-zero=true).
 * @param size Size of array.
 * @return Number of true values.
 */
EVERYUTIL_API int count_true(const int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_COUNT_TRUE_H