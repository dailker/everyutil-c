#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/color_hash.h"

EVERYUTIL_API int strings_equal(const char* a, const char* b) {
    if (a == NULL || b == NULL) return a == b;
    return strcmp(a, b) == 0;
}

void run_test(const char* test_name, const char* input) {
    char* result = color_hash(input);
    printf("%s: ", test_name);
    if (input && result != NULL) {
        printf("PASSED\n");
    } else if (!input && result == NULL) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
        printf("  Expected: %s\n", input ? "non-NULL" : "NULL");
        printf("  Got:      %s\n", result ? result : "NULL");
    }
    free(result);
}

int main(void) {
    run_test("valid input", "test");
    run_test("empty string", "");
    run_test("null input", NULL);
    return 0;
}