#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/color_name_to_hex.h"

EVERYUTIL_API int strings_equal(const char* a, const char* b) {
    if (a == NULL || b == NULL) return a == b;
    return strcmp(a, b) == 0;
}

void run_test(const char* test_name, const char* name, const char* expected) {
    const char* result = color_name_to_hex(name);
    printf ("Expected: %s\n", expected ? expected : "NULL");
    printf("  Got:      %s\n", result ? result : "NULL");
};


int main(void) {
    run_test("valid color name", "Sky Blue", "#87ceeb");
    run_test("case insensitive", "sky blue", "#87ceeb");
    run_test("invalid color name", "invalid", NULL);
    run_test("null name", NULL, NULL);
    run_test("empty name", "", NULL);
    return 0;
}