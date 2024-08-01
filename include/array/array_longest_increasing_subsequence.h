#ifndef ARRAY_ARRAY_LONGEST_INCREASING_SUBSEQUENCE_H
#define ARRAY_ARRAY_LONGEST_INCREASING_SUBSEQUENCE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_EVERYUTIL
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Finds the longest increasing subsequence (LIS) in a number array.
 *
 * @param array Input array of doubles.
 * @param length Length of the input array.
 * @param out_length Pointer to receive the length of the result.
 * @return Newly allocated array of LIS elements.
 *         NULL on failure. Caller must free the result.
 */
EVERYUTIL_API double* array_longest_increasing_subsequence(
    const double* array,
    size_t length,
    size_t* out_length
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_LONGEST_INCREASING_SUBSEQUENCE_H
