#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "array/array_longest_increasing_subsequence.h"

// Compare two double arrays for equality
bool arrays_equal(const double* a1, size_t len1, const double* a2, size_t len2) {
    if (len1 != len2) return false;
    for (size_t i = 0; i < len1; i++) {
        if (a1[i] != a2[i]) return false;
    }
    return true;
}

void test_lis_basic() {
    double input[] = {3, 1, 2, 1, 8, 5, 6};
    size_t out_len = 0;
    double* lis = array_longest_increasing_subsequence(input, 7, &out_len);

    double expected[] = {1, 2, 5, 6};
    if (lis && arrays_equal(lis, out_len, expected, 4)) {
        printf("test_lis_basic: PASSED\n");
    } else {
        printf("test_lis_basic: FAILED\n");
    }
    free(lis);
}

void test_lis_empty() {
    double input[] = {};
    size_t out_len = 0;
    double* lis = array_longest_increasing_subsequence(input, 0, &out_len);

    if (lis == NULL && out_len == 0) {
        printf("test_lis_empty: PASSED\n");
    } else {
        printf("test_lis_empty: FAILED\n");
    }
    free(lis);
}

int main() {
    test_lis_basic();
    test_lis_empty();
    return 0;
}