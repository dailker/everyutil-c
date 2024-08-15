#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "array/array_cumulative_product.h"

// Helper to compare double arrays for equality (exact match)
bool arrays_equal(const double* a, const double* b, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Helper to print double array
void print_array(const double* arr, size_t length) {
    printf("[");
    for (size_t i = 0; i < length; i++) {
        printf("%g", arr[i]);
        if (i + 1 < length) printf(", ");
    }
    printf("]");
}

// Test runner helper
void run_test(const char* test_name, const double* input, size_t input_len, const double* expected, size_t expected_len) {
    double* result = array_cumulative_product(input, input_len);
    printf("%s: ", test_name);

    if ((result == NULL && expected_len > 0) || (result != NULL && expected_len == 0)) {
        printf("FAILED (null mismatch)\n");
        free(result);
        return;
    }

    if (result == NULL && expected_len == 0) {
        // Both empty - pass
        printf("PASSED\n");
        return;
    }

    bool equal = (expected_len == input_len) && arrays_equal(result, expected, expected_len);
    if (equal) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
        printf("  Expected: ");
        print_array(expected, expected_len);
        printf("\n  Got:      ");
        print_array(result, input_len);
        printf("\n");
    }
    free(result);
}

int main(void) {
    // Test 1: cumulative product for positive numbers
    double input1[] = {1, 2, 3, 4};
    double expected1[] = {1, 2, 6, 24};
    run_test("returns cumulative product for positive numbers", input1, 4, expected1, 4);

    // Test 2: cumulative product with zero
    double input2[] = {2, 0, 4};
    double expected2[] = {2, 0, 0};
    run_test("returns cumulative product for array with zero", input2, 3, expected2, 3);

    // Test 3: empty input
    run_test("returns empty array for empty input", NULL, 0, NULL, 0);

    return 0;
}
