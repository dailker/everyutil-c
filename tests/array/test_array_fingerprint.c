#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "array/array_fingerprint.h"

// Helper to run a test and print pass/fail
void run_test(const char* test_name, const double* input1, size_t len1, const double* input2, size_t len2, bool expect_equal) {
    char* fp1 = array_fingerprint(input1, len1);
    char* fp2 = array_fingerprint(input2, len2);

    printf("%s: ", test_name);

    if (!fp1 || !fp2) {
        printf("FAILED (null fingerprint)\n");
        free(fp1);
        free(fp2);
        return;
    }

    bool are_equal = strcmp(fp1, fp2) == 0;

    if (expect_equal == are_equal) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
        printf("  fingerprint1: %s\n  fingerprint2: %s\n", fp1, fp2);
    }

    free(fp1);
    free(fp2);
}

int main(void) {
    // Test 1: returns a string fingerprint for a number array
    {
        double arr[] = {1, 2, 3};
        char* fp = array_fingerprint(arr, 3);
        printf("returns a string fingerprint for a number array: ");
        if (fp && strlen(fp) > 0) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
        free(fp);
    }

    // Test 2: returns different fingerprints for different arrays
    {
        double arr1[] = {1, 2, 3};
        double arr2[] = {3, 2, 1};
        run_test("returns different fingerprints for different arrays", arr1, 3, arr2, 3, false);
    }

    // Test 3: returns same fingerprint for same arrays
    {
        double arr1[] = {1, 2, 3};
        double arr2[] = {1, 2, 3};
        run_test("returns same fingerprint for same arrays", arr1, 3, arr2, 3, true);
    }

    return 0;
}
