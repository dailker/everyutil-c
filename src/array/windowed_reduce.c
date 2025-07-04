#include "array/windowed_reduce.h"
#include <stdlib.h>

EVERYUTIL_API void* windowedReduce(
    void** array,
    size_t length,
    windowed_reducer_fn reducer,
    void* initial_value,
    size_t window_size
) {
    if (!array || !reducer || window_size == 0 || length < window_size) return NULL;

    void* result = initial_value;
    for (size_t i = 0; i <= length - window_size; i++) {
        // Create window array
        void** window = (void**)malloc(window_size * sizeof(void*));
        if (!window) return NULL;

        // Populate window
        for (size_t j = 0; j < window_size; j++) {
            window[j] = array[i + j];
        }

        // Apply reducer
        result = reducer(result, window, window_size, i, array, length);
        free(window);

        if (!result) return NULL; // Reducer failed
    }

    return result;
}