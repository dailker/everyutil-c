#include "array/interleave.h"
#include <stdlib.h>

EVERYUTIL_API double* interleave(const double** arrays, const size_t* lengths,
                                 size_t arrays_count, size_t* out_length) {
    if (!arrays || !lengths || !out_length || arrays_count == 0) return NULL;

    size_t max_len = 0;
    size_t total_len = 0;
    for (size_t i = 0; i < arrays_count; ++i) {
        if (lengths[i] > max_len) max_len = lengths[i];
        total_len += lengths[i];
    }

    double* result = (double*)malloc(total_len * sizeof(double));
    if (!result) return NULL;

    size_t idx = 0;
    for (size_t i = 0; i < max_len; ++i) {
        for (size_t arr_i = 0; arr_i < arrays_count; ++arr_i) {
            if (i < lengths[arr_i]) {
                result[idx++] = arrays[arr_i][i];
            }
        }
    }

    *out_length = idx;
    return result;
}
