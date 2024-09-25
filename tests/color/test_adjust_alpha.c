#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/adjust_alpha.h"

EVERYUTIL_API int strings_equal(const char* a, const char* b) {
    if (a == NULL || b == NULL) return a == b;
    return strcmp(a, b) == 0;
}

void run_test(const char* test_name, const char* input, double alpha, const char* expected) {
    char* result = adjust_alpha(input, alpha);
    printf("%s: ", test_name);
    if (strings_equal(result, expected)) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
        printf("  Expected: %s\n", expected ? expected : "NULL");
        printf("  Got:      %s\n", result ? result : "NULL");
    }
    free(result);
}

int main(void) {
    run_test("hex color with valid alpha", "#336699", 0.5, "rgba(51,102,153,0.5)");
    run_test("rgb color with valid alpha", "rgb(51,102,153)", 0.3, "rgba(51,102,153,0.3)");
    run_test("invalid color", "invalid", 0.5, NULL);
    run_test("negative alpha", "#336699", -0.1, NULL);
    run_test("alpha greater than 1", "#336699", 1.5, NULL);
    run_test("alpha zero", "#336699", 0.0, "rgba(51,102,153,0)");
    run_test("alpha one", "#336699", 1.0, "rgba(51,102,153,1)");
    run_test("null color", NULL, 0.5, NULL);
    return 0;
}