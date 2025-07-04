#ifndef ARRAY_TIME_SERIES_DELTA_H
#define ARRAY_TIME_SERIES_DELTA_H

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
 * Computes difference between each element and the element `unit` positions before.
 * 
 * @param array Pointer to input numeric array.
 * @param length Number of elements in the input array.
 * @param unit Step size for difference calculation (must be > 0).
 * @param out_length Pointer to size_t to receive length of returned array.
 * @return Newly allocated array of differences (length = length - unit), or NULL on failure.
 */
EVERYUTIL_API double* time_series_delta(const double* array, size_t length, size_t unit, size_t* out_length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_TIME_SERIES_DELTA_H
