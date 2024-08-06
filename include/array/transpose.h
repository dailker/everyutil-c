#ifndef ARRAY_TRANSPOSE_H
#define ARRAY_TRANSPOSE_H

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
 * Transposes a jagged array of pointers.
 * 
 * @param array Pointer to an array of pointers to arrays (2D jagged array).
 * @param row_count Number of rows in the input array.
 * @param row_lengths Pointer to array containing length of each row.
 * @param out_col_count Pointer to receive the maximum row length (number of columns).
 * @return Pointer to newly allocated transposed array (array of arrays),
 *         or NULL on failure. Each row is NULL-terminated.
 *         Caller must free the outer array and each inner array.
 */
EVERYUTIL_API void*** transpose(void*** array, size_t row_count, const size_t* row_lengths, size_t* out_col_count);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_TRANSPOSE_H
