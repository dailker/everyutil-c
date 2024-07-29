#include "array/array_cumulative_product.h"
#include <stdlib.h>

EVERYUTIL_API double* array_cumulative_product(const double* array, size_t length) {
    if (!array && length > 0) return NULL;

    double* result = (double*)malloc(length * sizeof(double));
    if (!result) return NULL;

    double prod = 1.0;
    for (size_t i = 0; i < length; ++i) {
        prod *= array[i];
        result[i] = prod;
    }

    return result;
}
