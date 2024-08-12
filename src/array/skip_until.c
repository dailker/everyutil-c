#include "array/skip_until.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API void* skip_until(const void* array, size_t length, size_t element_size,
                               skip_until_predicate_fn predicate, void* user_data) {
    if (!array || length == 0 || element_size == 0 || !predicate) return NULL;

    const char* base = (const char*)array;
    for (size_t i = 0; i < length; i++) {
        if (predicate(base + i * element_size, i, array, length, user_data)) {
            size_t remain = length - i;
            void* result = malloc(remain * element_size);
            if (!result) return NULL;
            memcpy(result, base + i * element_size, remain * element_size);
            return result;
        }
    }
    return NULL;
}
