#include "array/zip_diagonals.h"
#include <stdlib.h>

EVERYUTIL_API diagonals_result_t zipDiagonals(void*** matrix, size_t rows, size_t cols) {
    diagonals_result_t result = {NULL, 0};
    if (!matrix || rows == 0 || cols == 0) return result;

    // Total number of diagonals is rows + cols - 1
    size_t diag_count = rows + cols - 1;
    result.diagonals = (void***)malloc(diag_count * sizeof(void**));
    if (!result.diagonals) return result;
    result.length = diag_count;

    // Allocate and populate each diagonal
    for (size_t d = 0; d < diag_count; d++) {
        // Calculate diagonal size
        size_t start_row = (d < cols) ? 0 : d - cols + 1;
        size_t start_col = (d < cols) ? d : cols - 1;
        size_t diag_size = 0;
        for (size_t i = start_row, j = start_col; i < rows && j < cols && j <= start_col; i++, j--) {
            if (j >= 0 && j < cols) diag_size++; // Ensure j doesn't underflow
        }

        // Allocate diagonal array
        result.diagonals[d] = (void**)malloc(diag_size * sizeof(void*));
        if (!result.diagonals[d]) {
            // Free previously allocated diagonals
            for (size_t k = 0; k < d; k++) {
                free(result.diagonals[k]);
            }
            free(result.diagonals);
            result.diagonals = NULL;
            result.length = 0;
            return result;
        }

        // Populate diagonal
        size_t index = 0;
        for (size_t i = start_row, j = start_col; i < rows && j < cols && j <= start_col; i++, j--) {
            if (j >= 0 && j < cols) {
                result.diagonals[d][index++] = matrix[i][j];
            }
        }
    }

    return result;
}

EVERYUTIL_API void freeDiagonalsResult(diagonals_result_t result) {
    if (!result.diagonals) return;
    for (size_t i = 0; i < result.length; i++) {
        free(result.diagonals[i]);
    }
    free(result.diagonals);
}