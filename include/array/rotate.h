#ifndef ARRAY_ROTATE_H
#define ARRAY_ROTATE_H

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
 * Rotates an array circularly by given positions.
 *
 * @param array Pointer to the input array.
 * @param length Number of elements in the array.
 * @param positions Number of positions to rotate (can be negative).
 * @param element_size Size of each element in bytes.
 * @return Newly allocated rotated array (caller must free), or NULL on failure.
 */
EVERYUTIL_API void* rotate_array(const void* array, size_t length, int positions, size_t element_size);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ROTATE_H
