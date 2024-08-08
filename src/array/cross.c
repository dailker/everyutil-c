#include "array/cross.h"
#include <stdlib.h>

EVERYUTIL_API CrossResult cross_product(void** arrayA, size_t lenA, void** arrayB, size_t lenB) {
    CrossResult result = { NULL, 0 };
    if (!arrayA || !arrayB || lenA == 0 || lenB == 0) {
        return result;
    }

    size_t total = lenA * lenB;
    CrossPair* pairs = malloc(total * sizeof(CrossPair));
    if (!pairs) return result;

    size_t idx = 0;
    for (size_t i = 0; i < lenA; i++) {
        for (size_t j = 0; j < lenB; j++) {
            pairs[idx].first = arrayA[i];
            pairs[idx].second = arrayB[j];
            idx++;
        }
    }

    result.pairs = pairs;
    result.length = total;
    return result;
}

EVERYUTIL_API void free_cross_result(CrossResult result) {
    free(result.pairs);
}
