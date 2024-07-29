#include "array/array_intersections.h"
#include <stdlib.h>
#include <string.h>

/**
 * Checks if a string exists in an array.
 */
static int string_in_array(const char* str, const char** array, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        if (strcmp(str, array[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

EVERYUTIL_API const char** array_intersections(
    const char*** arrays,
    const size_t* lengths,
    size_t num_arrays,
    size_t* out_length
) {
    if (!arrays || !lengths || num_arrays == 0 || !out_length) {
        return NULL;
    }

    const char** base = arrays[0];
    size_t base_len = lengths[0];
    const char** result = (const char**)malloc(base_len * sizeof(const char*));
    if (!result) return NULL;

    size_t count = 0;
    for (size_t i = 0; i < base_len; ++i) {
        const char* candidate = base[i];
        int found_in_all = 1;

        for (size_t j = 1; j < num_arrays; ++j) {
            if (!string_in_array(candidate, arrays[j], lengths[j])) {
                found_in_all = 0;
                break;
            }
        }

        if (found_in_all) {
            result[count++] = candidate;
        }
    }

    *out_length = count;
    return result;
}
