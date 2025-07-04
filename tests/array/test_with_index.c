#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array/with_index.h"

void test_with_index_basic() {
    char* items[] = {"a", "b", "c"};
    with_index_item_t* result = withIndex((void**)items, 3);

    int passed = (result != NULL);
    if (passed) {
        passed = passed && (result[0].value == items[0] && result[0].index == 0);
        passed = passed && (result[1].value == items[1] && result[1].index == 1);
        passed = passed && (result[2].value == items[2] && result[2].index == 2);
    }

    printf("test_with_index_basic: %s\n", passed ? "PASSED" : "FAILED");
    free(result);
}

void test_with_index_empty() {
    with_index_item_t* result = withIndex(NULL, 0);
    int passed = (result == NULL);
    printf("test_with_index_empty: %s\n", passed ? "PASSED" : "FAILED");
}

void test_with_index_single() {
    char* items[] = {"x"};
    with_index_item_t* result = withIndex((void**)items, 1);

    int passed = (result != NULL && result[0].value == items[0] && result[0].index == 0);
    printf("test_with_index_single: %s\n", passed ? "PASSED" : "FAILED");
    free(result);
}

int main(void) {
    test_with_index_basic();
    test_with_index_empty();
    test_with_index_single();
    return 0;
}