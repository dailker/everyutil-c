#include "array/zip_diagonals.h"
#include <stdlib.h>

diagonals_result_t zipDiagonals(void*** matrix, size_t rows, size_t cols) {
    diagonals_result_t result = {0, NULL};

    if (!matrix || rows == 0 || cols == 0) return result;

    size_t total_diags = rows + cols - 1;
    diagonal_t* diags = (diagonal_t*)malloc(total_diags * sizeof(diagonal_t));
    if (!diags) return result;

    for (size_t d = 0; d < total_diags; d++) {
        // max possible length of each diagonal is min(rows, cols)
        size_t capacity = (rows < cols) ? rows : cols;
        void** diag_items = (void**)malloc(capacity * sizeof(void*));
        if (!diag_items) {
            // free previously allocated diagonals
            for (size_t k = 0; k < d; k++) {
                free(diags[k].items);
            }
            free(diags);
            return (diagonals_result_t){0, NULL};
        }

        size_t diag_len = 0;
        for (size_t i = 0; i < rows; i++) {
            if (d < i) continue; // j would be negative, skip
            size_t j = d - i;
            if (j < cols) {
                diag_items[diag_len++] = matrix[i][j];
            }
        }

        // shrink diag_items if needed
        if (diag_len < capacity) {
            void** shrunk = (void**)realloc(diag_items, diag_len * sizeof(void*));
            if (shrunk) diag_items = shrunk;
        }

        diags[d].length = diag_len;
        diags[d].items = diag_items;
    }

    result.count = total_diags;
    result.diags = diags;
    return result;
}

void freeDiagonalsResult(diagonals_result_t result) {
    if (!result.diags) return;
    for (size_t i = 0; i < result.count; i++) {
        free(result.diags[i].items);
    }
    free(result.diags);
}
