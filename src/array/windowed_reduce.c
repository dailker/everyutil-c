#include <stdlib.h>
#include "array/windowed_reduce.h"

void* windowedReduce(
    void** array,
    size_t arrayLength,
    windowed_reduce_callback reducer,
    void* initialValue,
    size_t windowSize
) {
    if (!array || !reducer || !initialValue) return NULL;
    if (windowSize == 0 || windowSize > arrayLength) return NULL;

    void* acc = initialValue;

    // Temporary buffer to hold window elements pointers
    void** window = (void**)malloc(windowSize * sizeof(void*));
    if (!window) return NULL;

    for (size_t i = 0; i <= arrayLength - windowSize; i++) {
        // Copy pointers for current window
        for (size_t j = 0; j < windowSize; j++) {
            window[j] = array[i + j];
        }

        acc = reducer(acc, window, windowSize, i, array, arrayLength);
        if (!acc) {
            // reducer returned NULL - treat as failure
            free(window);
            return NULL;
        }
    }

    free(window);
    return acc;
}
