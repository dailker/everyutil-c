#include "array/tail_until.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API void* tail_until(const void* array, size_t length, size_t element_size, tail_until_predicate_fn predicate) {
    if (!array || length == 0 || element_size == 0 || !predicate) return NULL;

    // Find start index of tail
    ssize_t start = (ssize_t)length - 1;
    while (start >= 0) {
        const char* base = (const char*)array;
        const void* item = base + start * element_size;
        if (!predicate(item, (size_t)start, array, length)) {
            break;
        }
        start--;
    }
    start++; // move to first element that satisfies predicate from the tail

    size_t tail_len = length - (size_t)start;
    if (tail_len == 0) {
        // No elements satisfy predicate, return empty array
        void* empty = malloc(0);
        return empty;
    }

    // Allocate output array
    void* result = malloc(tail_len * element_size);
    if (!result) return NULL;

    memcpy(result, (const char*)array + start * element_size, tail_len * element_size);
    return result;
}
