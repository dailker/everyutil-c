#ifndef ARRAY_ARRAY_SPLICE_MULTIPLE_H
#define ARRAY_ARRAY_SPLICE_MULTIPLE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_EVERYUTIL
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Represents a splice instruction for the array.
 */
typedef struct {
    size_t start;            ///< Start index of splice.
    size_t delete_count;     ///< Number of elements to delete.
    const double* items;     ///< Items to insert (can be NULL).
    size_t item_count;       ///< Number of items to insert.
} array_splice_instruction_t;

/**
 * Splices multiple segments in one operation.
 *
 * @param array Input array.
 * @param length Length of the input array.
 * @param splices Array of splice instructions.
 * @param splice_count Number of splice instructions.
 * @param out_length Pointer to receive the length of the resulting array.
 * @return New array with splices applied. NULL on failure. Caller must free.
 */
EVERYUTIL_API double* array_splice_multiple(
    const double* array,
    size_t length,
    const array_splice_instruction_t* splices,
    size_t splice_count,
    size_t* out_length
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_SPLICE_MULTIPLE_H
