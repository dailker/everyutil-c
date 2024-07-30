#include "array/array_symmetric_difference.h"
#include <stdlib.h>
#include <stdbool.h>

static bool contains(const double* array, size_t len, double value) {
    for (size_t i = 0; i < len; ++i) {
        if (array[i] == value) return true;
    }
    return false;
}

EVERYUTIL_API double* array_symmetric_difference(
    const double* a, size_t a_len,
    const double* b, size_t b_len,
    size_t* out_len
) {
    if (!a || !b || !out_len) return NULL;

    double* temp = malloc((a_len + b_len) * sizeof(double));
    if (!temp) return NULL;

    size_t count = 0;

    // Elements in a not in b
    for (size_t i = 0; i < a_len; ++i) {
        if (!contains(b, b_len, a[i])) {
            temp[count++] = a[i];
        }
    }

    // Elements in b not in a
    for (size_t i = 0; i < b_len; ++i) {
        if (!contains(a, a_len, b[i])) {
            temp[count++] = b[i];
        }
    }

    // Final result
    double* result = malloc(count * sizeof(double));
    if (!result) {
        free(temp);
        return NULL;
    }

    for (size_t i = 0; i < count; ++i) {
        result[i] = temp[i];
    }

    free(temp);
    *out_len = count;
    return result;
}
