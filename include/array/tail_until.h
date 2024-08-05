#ifndef ARRAY_TAIL_UNTIL_H
#define ARRAY_TAIL_UNTIL_H

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
 * Predicate function prototype.
 * @param item Pointer to the current element.
 * @param idx Index of the current element.
 * @param arr Pointer to the whole array.
 * @param length Number of elements in the array.
 * @return Non-zero to continue, zero to stop.
 */
typedef int (*tail_until_predicate_fn)(const void* item, size_t idx, const void* arr, size_t length);

/**
 * Keeps tailing elements from the end of an array until predicate returns false.
 * 
 * @param array Pointer to the input array.
 * @param length Number of elements in the array.
 * @param element_size Size of each element in bytes.
 * @param predicate Function pointer to the predicate callback.
 * @return Newly allocated array containing the tail elements (caller must free), or NULL on failure.
 */
EVERYUTIL_API void* tail_until(const void* array, size_t length, size_t element_size, tail_until_predicate_fn predicate);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_TAIL_UNTIL_H
