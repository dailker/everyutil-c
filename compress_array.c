#include "array/compress_array.h"
#include <stdlib.h>

EVERYUTIL_API CompressArrayResult compress_array(const int* array, size_t length) {
    CompressArrayResult result = { NULL, 0 };
    if (!array || length == 0) return result;

    // Worst case: no compression, pairs count == length
    RLEPair* pairs = malloc(length * sizeof(RLEPair));
    if (!pairs) return result;

    size_t count = 1;
    size_t pair_idx = 0;
    int prev = array[0];

    for (size_t i = 1; i < length; i++) {
        if (array[i] == prev) {
            count++;
        } else {
            pairs[pair_idx].value = prev;
            pairs[pair_idx].count = count;
            pair_idx++;
            prev = array[i];
            count = 1;
        }
    }
    // push last pair
    pairs[pair_idx].value = prev;
    pairs[pair_idx].count = count;
    pair_idx++;

    // shrink allocation if needed
    if (pair_idx < length) {
        RLEPair* resized = realloc(pairs, pair_idx * sizeof(RLEPair));
        if (resized) {
            pairs = resized;
        }
    }

    result.pairs = pairs;
    result.length = pair_idx;
    return result;
}

EVERYUTIL_API void free_compress_array_result(CompressArrayResult result) {
    free(result.pairs);
}
