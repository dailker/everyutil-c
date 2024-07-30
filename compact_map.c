#include "array/compact_map.h"
#include <stdlib.h>

EVERYUTIL_API CompactMapResult compact_map(const int* array, size_t length, MapFunc fn) {
    CompactMapResult result = { NULL, 0 };
    if (!array || length == 0 || !fn) return result;

    int* temp = malloc(length * sizeof(int));
    if (!temp) return result;

    size_t count = 0;
    for (size_t i = 0; i < length; ++i) {
        int mapped = fn(array[i], i, array, length);
        if (mapped) {
            temp[count++] = mapped;
        }
    }

    if (count == 0) {
        free(temp);
        return result;
    }

    int* filtered = realloc(temp, count * sizeof(int));
    if (!filtered) {
        // realloc failure, keep temp as result anyway
        filtered = temp;
    }

    result.values = filtered;
    result.count = count;
    return result;
}

EVERYUTIL_API void free_compact_map_result(CompactMapResult result) {
    free(result.values);
}
