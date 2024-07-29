#include "array/array_splice_multiple.h"
#include <stdlib.h>
#include <string.h>

/** Comparison function to sort splices in descending order of `start` */
static int compare_splice_desc(const void* a, const void* b) {
    const array_splice_instruction_t* s1 = (const array_splice_instruction_t*)a;
    const array_splice_instruction_t* s2 = (const array_splice_instruction_t*)b;
    if (s1->start < s2->start) return 1;
    if (s1->start > s2->start) return -1;
    return 0;
}

EVERYUTIL_API double* array_splice_multiple(
    const double* array,
    size_t length,
    const array_splice_instruction_t* splices,
    size_t splice_count,
    size_t* out_length
) {
    if (!array || !splices || !out_length) return NULL;

    // Copy and sort splices descending by start
    array_splice_instruction_t* sorted = (array_splice_instruction_t*)malloc(splice_count * sizeof(array_splice_instruction_t));
    if (!sorted) return NULL;
    memcpy(sorted, splices, splice_count * sizeof(array_splice_instruction_t));
    qsort(sorted, splice_count, sizeof(array_splice_instruction_t), compare_splice_desc);

    // Estimate final length
    size_t final_length = length;
    for (size_t i = 0; i < splice_count; ++i) {
        if (sorted[i].start > final_length) {
            final_length = sorted[i].start;  // accommodate out-of-bounds insert
        }
        if (sorted[i].delete_count > final_length - sorted[i].start)
            sorted[i].delete_count = final_length - sorted[i].start;
        final_length = final_length - sorted[i].delete_count + sorted[i].item_count;
    }

    // Allocate result
    double* result = (double*)malloc(final_length * sizeof(double));
    if (!result) {
        free(sorted);
        return NULL;
    }

    // Copy original array to a buffer we can edit in-place
    double* temp = (double*)malloc((length + 1) * sizeof(double)); // +1 in case of safety
    if (!temp) {
        free(result);
        free(sorted);
        return NULL;
    }
    memcpy(temp, array, length * sizeof(double));

    size_t temp_len = length;

    // Apply each splice from back to front
    for (size_t i = 0; i < splice_count; ++i) {
        array_splice_instruction_t s = sorted[i];
        size_t left_len = s.start;
        size_t right_len = temp_len - s.start - s.delete_count;

        // Allocate a new temp array
        double* new_temp = (double*)malloc((left_len + s.item_count + right_len) * sizeof(double));
        if (!new_temp) {
            free(temp);
            free(result);
            free(sorted);
            return NULL;
        }

        memcpy(new_temp, temp, left_len * sizeof(double));  // left
        if (s.items && s.item_count > 0)
            memcpy(new_temp + left_len, s.items, s.item_count * sizeof(double));  // inserted items
        memcpy(new_temp + left_len + s.item_count, temp + s.start + s.delete_count, right_len * sizeof(double));  // right

        free(temp);
        temp = new_temp;
        temp_len = left_len + s.item_count + right_len;
    }

    memcpy(result, temp, temp_len * sizeof(double));
    *out_length = temp_len;

    free(temp);
    free(sorted);
    return result;
}
