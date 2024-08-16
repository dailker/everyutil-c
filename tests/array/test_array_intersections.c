#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "array/array_intersections.h"

// Helper: compare two string arrays for equality (order matters)
bool arrays_equal(const char** a1, size_t len1, const char** a2, size_t len2) {
    if (len1 != len2) return false;
    for (size_t i = 0; i < len1; i++) {
        if (strcmp(a1[i], a2[i]) != 0) return false;
    }
    return true;
}

void test_intersection_basic() {
    const char* arr1[] = {"1", "2", "3"};
    const char* arr2[] = {"2", "3", "4"};
    const char** arrays[] = {arr1, arr2};
    size_t lengths[] = {3, 3};
    size_t out_len = 0;

    const char** result = array_intersections(arrays, lengths, 2, &out_len);

    const char* expected[] = {"2", "3"};
    if (result && arrays_equal(result, out_len, expected, 2)) {
        printf("test_intersection_basic: PASSED\n");
    } else {
        printf("test_intersection_basic: FAILED\n");
    }

    free(result);
}

void test_intersection_empty() {
    const char* arr1[] = {"1", "2"};
    const char* arr2[] = {"3", "4"};
    const char** arrays[] = {arr1, arr2};
    size_t lengths[] = {2, 2};
    size_t out_len = 0;

    const char** result = array_intersections(arrays, lengths, 2, &out_len);

    if (result && out_len == 0) {
        printf("test_intersection_empty: PASSED\n");
    } else {
        printf("test_intersection_empty: FAILED\n");
    }

    free(result);
}

int main() {
    test_intersection_basic();
    test_intersection_empty();
    return 0;
}
