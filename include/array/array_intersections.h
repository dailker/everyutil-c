#ifndef ARRAY_ARRAY_INTERSECTIONS_H
#define ARRAY_ARRAY_INTERSECTIONS_H

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
 * Finds common elements across multiple string arrays.
 *
 * @param arrays Array of string array pointers.
 * @param lengths Array of lengths corresponding to each string array.
 * @param num_arrays Number of input arrays.
 * @param out_length Pointer to receive the length of the result array.
 * @return Newly allocated array of strings present in all input arrays.
 *         Returns NULL on failure. Caller must free the returned array.
 */
EVERYUTIL_API const char** array_intersections(
    const char*** arrays,
    const size_t* lengths,
    size_t num_arrays,
    size_t* out_length
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_INTERSECTIONS_H
