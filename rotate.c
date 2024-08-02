#include "array/rotate.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API void* rotate_array(const void* array, size_t length, int positions, size_t element_size) {
    if (!array || length == 0 || element_size == 0) return NULL;

    // Normalize rotation count
    int n = positions % (int)length;
    if (n < 0) n += length;

    void* rotated = malloc(length * element_size);
    if (!rotated) return NULL;

    // Copy last n elements to start
    memcpy(rotated, (const char*)array + (length - n) * element_size, n * element_size);
    // Copy first (length - n) elements after
    memcpy((char*)rotated + n * element_size, array, (length - n) * element_size);

    return rotated;
}
