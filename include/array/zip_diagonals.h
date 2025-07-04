#ifndef ARRAY_ZIP_DIAGONALS_H
#define ARRAY_ZIP_DIAGONALS_H

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
 * Struct to hold the result of zipping matrix diagonals.
 */
typedef struct {
    void*** diagonals; // Array of diagonal arrays
    size_t length;     // Number of diagonals
} diagonals_result_t;

/**
 * Extracts diagonals from a matrix in a zigzag pattern (top-left to bottom-right).
 * @param matrix Input matrix as an array of arrays of pointers.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return A diagonals_result_t containing the extracted diagonals.
 *         Returns {NULL, 0} on error (e.g., invalid input or memory allocation failure).
 * Caller must free the result using freeDiagonalsResult().
 */
EVERYUTIL_API diagonals_result_t zipDiagonals(void*** matrix, size_t rows, size_t cols);

/**
 * Frees the memory allocated for the diagonals result.
 * @param result The diagonals result to free.
 */
EVERYUTIL_API void freeDiagonalsResult(diagonals_result_t result);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ZIP_DIAGONALS_H