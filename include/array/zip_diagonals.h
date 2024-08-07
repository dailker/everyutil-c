#ifndef ARRAY_ZIP_DIAGONALS_H
#define ARRAY_ZIP_DIAGONALS_H

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
 * Represents a single diagonal slice (an array of void* items).
 */
typedef struct {
    size_t length;
    void** items;  // dynamically allocated array of pointers for this diagonal
} diagonal_t;

/**
 * Holds the result: an array of diagonals.
 */
typedef struct {
    size_t count;      // number of diagonals
    diagonal_t* diags; // dynamically allocated array of diagonal_t
} diagonals_result_t;

/**
 * Computes diagonal zipping of a 2D matrix.
 * 
 * @param matrix Pointer to an array of pointers, each pointing to a row array.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return A diagonals_result_t struct with diagonals allocated dynamically.
 *         Caller must free via freeDiagonalsResult().
 *         Returns count = 0 and diags = NULL on failure or empty input.
 */
EVERYUTIL_API diagonals_result_t zipDiagonals(void*** matrix, size_t rows, size_t cols);

/**
 * Frees a diagonals_result_t previously returned by zipDiagonals.
 * 
 * @param result The diagonals_result_t to free.
 */
EVERYUTIL_API void freeDiagonalsResult(diagonals_result_t result);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ZIP_DIAGONALS_H
