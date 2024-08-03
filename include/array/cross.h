#ifndef ARRAY_CROSS_H
#define ARRAY_CROSS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_EVERYUTIL
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

/**
 * Pair of generic pointers.
 */
typedef struct {
    void* first;
    void* second;
} CrossPair;

/**
 * Result of cross product: dynamically allocated array of CrossPair.
 */
typedef struct {
    CrossPair* pairs;
    size_t length;
} CrossResult;

/**
 * Computes the Cartesian product of two arrays of pointers.
 * Returns a CrossResult with pairs and length.
 * Caller must free the returned pairs array using free_cross_result().
 * 
 * @param arrayA pointer to first array of void* elements
 * @param lenA length of first array
 * @param arrayB pointer to second array of void* elements
 * @param lenB length of second array
 * @return CrossResult with dynamically allocated pairs array or {NULL, 0} on failure
 */
EVERYUTIL_API CrossResult cross_product(void** arrayA, size_t lenA, void** arrayB, size_t lenB);

/**
 * Frees memory allocated by cross_product.
 * @param result CrossResult to free
 */
EVERYUTIL_API void free_cross_result(CrossResult result);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_CROSS_H
