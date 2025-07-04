#ifndef ARRAY_MUTATE_BY_NOISE_H
#define ARRAY_MUTATE_BY_NOISE_H

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
 * Applies light randomness ("noise") to numeric array elements.
 *
 * @param array Input array of doubles.
 * @param length Number of elements in the array.
 * @param strength Noise strength multiplier (default 0.1).
 * @return Newly allocated mutated array (caller must free), or NULL on failure.
 */
EVERYUTIL_API double* mutate_by_noise(const double* array, size_t length, double strength);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_MUTATE_BY_NOISE_H
