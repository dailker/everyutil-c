#ifndef ARRAY_COMPACT_MAP_H
#define ARRAY_COMPACT_MAP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

/**
 * Function pointer type for mapping function from int to int.
 * @param item input element
 * @param idx index of element
 * @param arr pointer to original array
 * @param length length of original array
 * @return mapped value (0 treated as falsy and filtered out)
 */
typedef int (*MapFunc)(int item, size_t idx, const int* arr, size_t length);

/**
 * Result structure for compactMap:
 * - values: dynamically allocated array of mapped non-zero values
 * - count: number of elements in values
 */
typedef struct {
    int* values;
    size_t count;
} CompactMapResult;

/**
 * Maps values of input array using `fn`, filtering out falsy (zero) results.
 * Caller must free the returned CompactMapResult.values using free().
 * 
 * @param array input array
 * @param length length of input array
 * @param fn mapping function
 * @return CompactMapResult with filtered mapped values, or {NULL,0} on failure
 */
EVERYUTIL_API CompactMapResult compact_map(const int* array, size_t length, MapFunc fn);

/**
 * Frees memory allocated by compact_map.
 * @param result CompactMapResult to free
 */
EVERYUTIL_API void free_compact_map_result(CompactMapResult result);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_COMPACT_MAP_H
