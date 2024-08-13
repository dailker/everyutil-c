#include "array/shuffle_stable.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API void* shuffle_stable(const void* array, size_t length, size_t element_size, unsigned int seed) {
    if (!array || length == 0 || element_size == 0) return NULL;

    // Allocate copy
    void* result = malloc(length * element_size);
    if (!result) return NULL;
    memcpy(result, array, length * element_size);

    // LCG parameters
    unsigned int state = seed;
    unsigned int a = 9301;
    unsigned int c = 49297;
    unsigned int m = 233280;

    // Fisher–Yates shuffle using deterministic PRNG
    for (size_t i = length - 1; i > 0; --i) {
        state = (state * a + c) % m;
        double rnd = (double)state / (double)m;
        size_t j = (size_t)(rnd * (i + 1));

        // Swap elements at i and j
        char* base = (char*)result;
        char temp[element_size];

        memcpy(temp, base + i * element_size, element_size);
        memcpy(base + i * element_size, base + j * element_size, element_size);
        memcpy(base + j * element_size, temp, element_size);
    }

    return result;
}
