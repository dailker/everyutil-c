#ifndef ARRAY_ARRAY_STABLE_SORT_H
#define ARRAY_ARRAY_STABLE_SORT_H

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
 * Stable sort for arrays of doubles using a custom comparison function.
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the array.
 * @param compare Comparison function. Must return <0, 0, or >0 like strcmp.
 * @return Newly allocated sorted array. Caller must free. NULL on failure.
 */
EVERYUTIL_API double* array_stable_sort(
    const double* array,
    size_t length,
    int (*compare)(double a, double b)
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_STABLE_SORT_H
