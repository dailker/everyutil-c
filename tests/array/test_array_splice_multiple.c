#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "array/array_splice_multiple.h"

bool arrays_equal(const double* a, const double* b, size_t length) {
    for (size_t i = 0; i < length; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void test_splice_multiple() {
    double arr[] = {1,2,3,4,5};
    array_splice_instruction_t splices[] = {
        { .start = 1, .delete_count = 2, .items = (double[]){9,9}, .item_count = 2 },
        { .start = 4, .delete_count = 1, .items = (double[]){7},   .item_count = 1 }
    };
    size_t out_len = 0;
    double* result = array_splice_multiple(arr, 5, splices, 2, &out_len);
    double expected[] = {1,9,9,4,7};

    if (result && out_len == 5 && arrays_equal(result, expected, out_len)) {
        printf("test_splice_multiple: PASSED\n");
    } else {
        printf("test_splice_multiple: FAILED\n");
    }
    free(result);
}

void test_empty_splices() {
    double arr[] = {1,2,3};
    size_t out_len = 0;
    double* result = array_splice_multiple(arr, 3, NULL, 0, &out_len);
    double expected[] = {1,2,3};

    if (result && out_len == 3 && arrays_equal(result, expected, out_len)) {
        printf("test_empty_splices: PASSED\n");
    } else {
        printf("test_empty_splices: FAILED\n");
    }
    free(result);
}

int main() {
    test_splice_multiple();
    test_empty_splices();
    return 0;
}
