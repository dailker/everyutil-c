#include "array/time_series_delta.h"
#include <stdlib.h>

EVERYUTIL_API double* time_series_delta(const double* array, size_t length, size_t unit, size_t* out_length) {
    if (!array || length == 0 || unit == 0 || unit >= length || !out_length) return NULL;

    size_t result_len = length - unit;
    double* result = (double*)malloc(result_len * sizeof(double));
    if (!result) return NULL;

    for (size_t i = unit; i < length; ++i) {
        result[i - unit] = array[i] - array[i - unit];
    }

    *out_length = result_len;
    return result;
}
