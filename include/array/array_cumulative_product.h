#ifndef ARRAY_ARRAY_CUMULATIVE_PRODUCT_H
#define ARRAY_ARRAY_CUMULATIVE_PRODUCT_H

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
 * Returns the cumulative product of a double array.
 *
 * @param array Pointer to input array of doubles.
 * @param length Number of elements in the input array.
 * @return Pointer to a newly allocated array containing cumulative products.
 *         Returns NULL on failure. Caller must free the returned array.
 */
EVERYUTIL_API double* array_cumulative_product(const double* array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_CUMULATIVE_PRODUCT_H
