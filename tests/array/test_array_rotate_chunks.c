#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array/array_rotate_chunks.h"

bool arrays_equal(const double* a, const double* b, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    double input[] = {1, 2, 3, 4, 5, 6};
    size_t length = sizeof(input) / sizeof(input[0]);
    size_t chunk_size = 2;
    int count = 1;

    double* rotated = array_rotate_chunks(input, length, chunk_size, count);
    if (!rotated) {
        printf("array_rotate_chunks returned NULL\n");
        return 1;
    }

    double expected[] = {5, 6, 1, 2, 3, 4};
    if (arrays_equal(rotated, expected, length)) {
        printf("Test PASSED\n");
    } else {
        printf("Test FAILED\nExpected: ");
        for (size_t i = 0; i < length; i++) printf("%g ", expected[i]);
        printf("\nGot:      ");
        for (size_t i = 0; i < length; i++) printf("%g ", rotated[i]);
        printf("\n");
    }

    free(rotated);
    return 0;
}
