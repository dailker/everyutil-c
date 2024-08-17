#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "array/array_stable_sort.h"

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

// Ascending comparator
int cmp_asc(double a, double b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

// Descending comparator
int cmp_desc(double a, double b) {
    if (a > b) return -1;
    if (a < b) return 1;
    return 0;
}

void run_test(const char* test_name, const double* input, size_t input_len, const double* expected, size_t expected_len, int (*cmp)(double, double)) {
    double* result = array_stable_sort(input, input_len, cmp);
    printf("%s: ", test_name);

    if ((result == NULL && expected_len > 0) || (result != NULL && expected_len == 0)) {
        printf("FAILED (null mismatch)\n");
        free(result);
        return;
    }

    if (result == NULL && expected_len == 0) {
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
    double input1[] = {3, 1, 2, 4};
    double expected1[] = {1, 2, 3, 4};
    run_test("sorts ascending", input1, 4, expected1, 4, cmp_asc);

    double input2[] = {3, 1, 2, 4};
    double expected2[] = {4, 3, 2, 1};
    run_test("sorts descending", input2, 4, expected2, 4, cmp_desc);

    run_test("empty input", NULL, 0, NULL, 0, cmp_asc);
    return 0;
}
