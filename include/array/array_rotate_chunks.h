#ifndef ARRAY_ARRAY_ROTATE_CHUNKS_H
#define ARRAY_ARRAY_ROTATE_CHUNKS_H

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
 * Rotates an array in chunks of N elements.
 *
 * @param array Input array of doubles.
 * @param length Length of the input array.
 * @param chunk_size Size of each chunk to rotate.
 * @param count Number of chunk rotations (positive = right, negative = left).
 * @return New rotated array. NULL on failure. Caller must free.
 */
EVERYUTIL_API double* array_rotate_chunks(
    const double* array,
    size_t length,
    size_t chunk_size,
    int count
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_ROTATE_CHUNKS_H
