#include "array/detect_pattern.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API PatternResult detect_pattern(const int* array, size_t length) {
    PatternResult result = { NULL, 0, 0 };
    if (!array || length == 0) return result;

    // Try all possible pattern lengths from 1 to length/2
    for (size_t len = 1; len <= length / 2; len++) {
        if (length % len != 0) continue; // pattern length must divide total length exactly

        // Check if every chunk matches the first pattern chunk
        int match = 1;
        for (size_t i = 0; i < length; i += len) {
            for (size_t j = 0; j < len; j++) {
                if (array[i + j] != array[j]) {
                    match = 0;
                    break;
                }
            }
            if (!match) break;
        }

        if (match) {
            int* pat = (int*)malloc(len * sizeof(int));
            if (!pat) break;
            memcpy(pat, array, len * sizeof(int));
            result.pattern = pat;
            result.pattern_len = len;
            result.repeats = length / len;
            return result;
        }
    }

    // No pattern found
    return result;
}

EVERYUTIL_API void free_pattern_result(PatternResult result) {
    free(result.pattern);
}
