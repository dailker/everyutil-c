#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array/windowed_reduce.h"

void* concat_strings(void* acc, void** window, size_t window_size, size_t index, void** array, size_t array_length) {
    char* result = acc ? (char*)acc : strdup("");
    if (!result) return NULL;

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%zu:", index);
    size_t len = strlen(result) + strlen(buffer) + 1;
    for (size_t i = 0; i < window_size; i++) {
        len += strlen((char*)window[i]) + 1;
    }

    char* new_result = (char*)realloc(result, len);
    if (!new_result) {
        free(result);
        return NULL;
    }
    result = new_result;
    strcat(result, buffer);

    for (size_t i = 0; i < window_size; i++) {
        strcat(result, (char*)window[i]);
        if (i < window_size - 1) strcat(result, ",");
    }

    return result;
}

void test_windowed_reduce_basic() {
    char* items[] = {"a", "b", "c", "d"};
    char* initial = strdup("");
    void* result = windowedReduce((void**)items, 4, concat_strings, initial, 2);

    int passed = result && strcmp((char*)result, "0:a,b1:b,c2:c,d") == 0;
    printf("test_windowed_reduce_basic: %s\n", passed ? "PASSED" : "FAILED");
    free(result); // Free result (initial + concatenated strings)
}

void test_windowed_reduce_empty() {
    void* result = windowedReduce(NULL, 0, concat_strings, NULL, 1);
    int passed = (result == NULL);
    printf("test_windowed_reduce_empty: %s\n", passed ? "PASSED" : "FAILED");
}

void test_windowed_reduce_invalid_window() {
    char* items[] = {"a", "b"};
    void* result = windowedReduce((void**)items, 2, concat_strings, NULL, 3);
    int passed = (result == NULL);
    printf("test_windowed_reduce_invalid_window: %s\n", passed ? "PASSED" : "FAILED");
}

int main(void) {
    test_windowed_reduce_basic();
    test_windowed_reduce_empty();
    test_windowed_reduce_invalid_window();
    return 0;
}