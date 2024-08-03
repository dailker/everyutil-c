#ifndef ARRAY_COMPRESS_ARRAY_H
#define ARRAY_COMPRESS_ARRAY_H

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
 * Run-length encoding pair for int arrays.
 */
typedef struct {
    int value;
    size_t count;
} RLEPair;

/**
 * Result structure for compress_array:
 * - pairs: dynamically allocated array of RLEPair
 * - length: number of pairs
 */
typedef struct {
    RLEPair* pairs;
    size_t length;
} CompressArrayResult;

/**
 * Compresses an int array using run-length encoding.
 * Caller must free the returned CompressArrayResult.pairs using free().
 * 
 * @param array input int array
 * @param length length of input array
 * @return CompressArrayResult with RLE pairs or {NULL, 0} on failure or empty input
 */
EVERYUTIL_API CompressArrayResult compress_array(const int* array, size_t length);

/**
 * Frees memory allocated by compress_array.
 * @param result CompressArrayResult to free
 */
EVERYUTIL_API void free_compress_array_result(CompressArrayResult result);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_COMPRESS_ARRAY_H
