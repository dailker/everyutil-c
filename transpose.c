#include "array/transpose.h"
#include <stdlib.h>

EVERYUTIL_API void*** transpose(void*** array, size_t row_count, const size_t* row_lengths, size_t* out_col_count) {
    if (!array || row_count == 0 || !row_lengths || !out_col_count) return NULL;

    // Find max length among rows
    size_t max_len = 0;
    for (size_t i = 0; i < row_count; ++i) {
        if (row_lengths[i] > max_len) {
            max_len = row_lengths[i];
        }
    }
    *out_col_count = max_len;

    // Allocate array for transposed rows (columns)
    void*** result = (void***)malloc(max_len * sizeof(void**));
    if (!result) return NULL;

    for (size_t col = 0; col < max_len; ++col) {
        // Allocate each transposed row with length = row_count + 1 for NULL termination
        void** new_row = (void**)malloc((row_count + 1) * sizeof(void*));
        if (!new_row) {
            // Cleanup on failure
            for (size_t k = 0; k < col; ++k) {
                free(result[k]);
            }
            free(result);
            return NULL;
        }

        for (size_t row = 0; row < row_count; ++row) {
            if (col < row_lengths[row]) {
                new_row[row] = array[row][col];
            } else {
                new_row[row] = NULL;  // no element in this position
            }
        }
        new_row[row_count] = NULL; // NULL-terminate the array for convenience
        result[col] = new_row;
    }

    return result;
}
