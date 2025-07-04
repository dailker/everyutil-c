#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array/semantic_group.h"

// Sample item struct for testing
typedef struct {
    int value;
    const char* type;
} test_item_t;

// Type function for test items
const char* get_item_type(void* item) {
    if (!item) return NULL;
    return ((test_item_t*)item)->type;
}

// Helper to check group contents
int check_group(semantic_group_t* group, const char* expected_type, test_item_t** expected_items, size_t expected_count) {
    if (strcmp(group->type, expected_type) != 0) return 0;
    if (group->count != expected_count) return 0;
    for (size_t i = 0; i < expected_count; i++) {
        if (group->items[i] != expected_items[i]) return 0;
    }
    return 1;
}

void test_semantic_group_basic() {
    test_item_t items[] = {
        {1, "even"}, {2, "odd"}, {3, "odd"}, {4, "even"}
    };
    semantic_group_result_t result = {0};
    int ret = semantic_group((void**)items, 4, get_item_type, &result);

    int passed = (ret == 0 && result.count == 2);
    if (passed) {
        passed = passed && check_group(&result.groups[0], "even", (test_item_t*[]){&items[0], &items[3]}, 2);
        passed = passed && check_group(&result.groups[1], "odd", (test_item_t*[]){&items[1], &items[2]}, 2);
    }

    printf("test_semantic_group_basic: %s\n", passed ? "PASSED" : "FAILED");
    semantic_group_free(&result);
}

void test_semantic_group_empty() {
    semantic_group_result_t result = {0};
    int ret = semantic_group(NULL, 0, get_item_type, &result);

    int passed = (ret == -1 && result.count == 0 && result.groups == NULL);
    printf("test_semantic_group_empty: %s\n", passed ? "PASSED" : "FAILED");
    semantic_group_free(&result);
}

void test_semantic_group_single_type() {
    test_item_t items[] = {{1, "number"}, {2, "number"}};
    semantic_group_result_t result = {0};
    int ret = semantic_group((void**)items, 2, get_item_type, &result);

    int passed = (ret == 0 && result.count == 1);
    if (passed) {
        passed = check_group(&result.groups[0], "number", (test_item_t*[]){&items[0], &items[1]}, 2);
    }

    printf("test_semantic_group_single_type: %s\n", passed ? "PASSED" : "FAILED");
    semantic_group_free(&result);
}

int main(void) {
    test_semantic_group_basic();
    test_semantic_group_empty();
    test_semantic_group_single_type();
    return 0;
}