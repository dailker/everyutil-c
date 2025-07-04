#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array/zip_diagonals.h"

// Helper to check diagonal contents
int check_diagonal(void** diagonal, size_t len, const char* expected[], size_t expected_len) {
    if (len != expected_len) return 0;
    for (size_t i = 0; i < len; i++) {
        if (strcmp((char*)diagonal[i], expected[i]) != 0) return 0;
    }
    return 1;
}

void test_zip_diagonals_basic() {
    // 3x3 matrix: ["a", "b", "c"], ["d", "e", "f"], ["g", "h", "i"]
    // Diagonals: ["a"], ["b", "d"], ["c", "e", "g"], ["f", "h"], ["i"]
    char* matrix[3][3] = {
        {"a", "b", "c"},
        {"d", "e", "f"},
        {"g", "h", "i"}
    };
    void*** input = (void***)malloc(3 * sizeof(void**));
    for (size_t i = 0; i < 3; i++) {
        input[i] = (void**)matrix[i];
    }

    diagonals_result_t result = zipDiagonals(input, 3, 3);
    int passed = (result.length == 5);
    if (passed) {
        passed = passed && check_diagonal(result.diagonals[0], 1, (const char*[]){"a"}, 1);
        passed = passed && check_diagonal(result.diagonals[1], 2, (const char*[]){"b", "d"}, 2);
        passed = passed && check_diagonal(result.diagonals[2], 3, (const char*[]){"c", "e", "g"}, 3);
        passed = passed && check_diagonal(result.diagonals[3], 2, (const char*[]){"f", "h"}, 2);
        passed = passed && check_diagonal(result.diagonals[4], 1, (const char*[]){"i"}, 1);
    }

    printf("test_zip_diagonals_basic: %s\n", passed ? "PASSED" : "FAILED");
    freeDiagonalsResult(result);
    free(input);
}

void test_zip_diagonals_empty() {
    diagonals_result_t result = zipDiagonals(NULL, 0, 0);
    int passed = (result.diagonals == NULL && result.length == 0);
    printf("test_zip_diagonals_empty: %s\n", passed ? "PASSED" : "FAILED");
    freeDiagonalsResult(result);
}

void test_zip_diagonals_single() {
    char* matrix[1][1] = {{"a"}};
    void*** input = (void***)malloc(1 * sizeof(void**));
    input[0] = (void**)matrix[0];

    diagonals_result_t result = zipDiagonals(input, 1, 1);
    int passed = (result.length == 1 && check_diagonal(result.diagonals[0], 1, (const char*[]){"a"}, 1));
    printf("test_zip_diagonals_single: %s\n", passed ? "PASSED" : "FAILED");
    freeDiagonalsResult(result);
    free(input);
}

int main(void) {
    test_zip_diagonals_basic();
    test_zip_diagonals_empty();
    test_zip_diagonals_single();
    return 0;
}