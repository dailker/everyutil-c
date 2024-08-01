#ifndef ARRAY_ARRAY_SYMMETRIC_DIFFERENCE_H
#define ARRAY_ARRAY_SYMMETRIC_DIFFERENCE_H

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
 * Returns the symmetric difference of two arrays of doubles.
 *
 * @param a First array.
 * @param a_len Length of first array.
 * @param b Second array.
 * @param b_len Length of second array.
 * @param out_len Pointer to size_t where result length will be stored.
 * @return Dynamically allocated array of symmetric difference values. Caller must free. NULL on failure.
 */
EVERYUTIL_API double* array_symmetric_difference(
    const double* a, size_t a_len,
    const double* b, size_t b_len,
    size_t* out_len
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_SYMMETRIC_DIFFERENCE_H
