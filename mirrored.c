#include "array/mirrored.h"

EVERYUTIL_API int mirrored(const double* array, size_t length) {
    if (!array || length < 2) return 1; // trivially mirrored

    size_t i = 0, j = length - 1;
    while (i < j) {
        if (array[i] != array[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
