#include "array/is_uniform.h"

EVERYUTIL_API int is_uniform(const double* array, size_t length) {
    if (!array || length == 0) return 1;

    double first = array[0];
    for (size_t i = 1; i < length; ++i) {
        if (array[i] != first) return 0;
    }
    return 1;
}
