#include "array/slide_window.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API slide_window_result_t slide_window(const void* array, size_t length, size_t element_size, size_t size, size_t step) {
    slide_window_result_t result = { NULL, 0 };

    if (!array || length == 0 || element_size == 0 || size == 0 || step == 0) {
        return result;
    }
    if (size > length) {
        return result;
    }

    size_t max_windows = 1 + (length - size) / step;
    void** windows = (void**)malloc(max_windows * sizeof(void*));
    if (!windows) return result;

    const char* base = (const char*)array;
    size_t count = 0;

    for (size_t i = 0; i + size <= length; i += step) {
        void* chunk = malloc(size * element_size);
        if (!chunk) {
            // free previously allocated chunks
            for (size_t j = 0; j < count; j++) {
                free(windows[j]);
            }
            free(windows);
            return (slide_window_result_t){ NULL, 0 };
        }
        memcpy(chunk, base + i * element_size, size * element_size);
        windows[count++] = chunk;
    }

    result.windows = windows;
    result.count = count;
    return result;
}
