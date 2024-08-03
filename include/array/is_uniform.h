#ifndef ARRAY_IS_UNIFORM_H
#define ARRAY_IS_UNIFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_EXPORTS
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Checks if all elements in the double array are equal.
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the array.
 * @return 1 if all elements are equal or array is empty, 0 otherwise.
 */
EVERYUTIL_API int is_uniform(const double* array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_IS_UNIFORM_H
