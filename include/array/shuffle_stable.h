#ifndef ARRAY_SHUFFLE_STABLE_H
#define ARRAY_SHUFFLE_STABLE_H

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
 * Deterministically shuffles an array based on a seed.
 * 
 * @param array Pointer to input array.
 * @param length Number of elements in array.
 * @param element_size Size of each element in bytes.
 * @param seed Seed value (positive integer).
 * @return Newly allocated shuffled array (caller must free), or NULL on failure.
 */
EVERYUTIL_API void* shuffle_stable(const void* array, size_t length, size_t element_size, unsigned int seed);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_SHUFFLE_STABLE_H
