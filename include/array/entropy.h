#ifndef ARRAY_ENTROPY_H
#define ARRAY_ENTROPY_H

#ifdef __cplusplus
extern "C" {
#endif

// EVERYUTIL_API macro for DLL export/import
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
 * Calculates the Shannon entropy of a double array.
 *
 * @param array Pointer to the input array of doubles.
 * @param length Number of elements in the array.
 * @return Shannon entropy value (base 2). Returns 0 if length is 0.
 */
EVERYUTIL_API double entropy(const double* array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ENTROPY_H
