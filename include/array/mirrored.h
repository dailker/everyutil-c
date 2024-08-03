#ifndef ARRAY_MIRRORED_H
#define ARRAY_MIRRORED_H

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
 * Checks if the array is symmetrical (mirrored).
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the array.
 * @return 1 if mirrored, 0 otherwise.
 */
EVERYUTIL_API int mirrored(const double* array, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_MIRRORED_H
