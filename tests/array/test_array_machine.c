#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "array/array_machine.h"

bool arrays_equal(const double* a, const double* b, size_t len) {
    for (size_t i = 0; i < len; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    double input[] = {1, 2, 3};
    ArrayInstruction instructions[] = {
        {ARRAY_OP_SET, 0, 0, 2},  // set index 0 to 2
        {ARRAY_OP_ADD, 1, 0, 2},  // add 2 to index 1
        {ARRAY_OP_SWAP, 0, 1, 0}  // swap index 0 and 1
    };

    size_t len = sizeof(input) / sizeof(input[0]);
    size_t num_instructions = sizeof(instructions) / sizeof(instructions[0]);

    double* result = array_machine(input, len, instructions, num_instructions);
    if (!result) {
        printf("array_machine returned NULL\n");
        return 1;
    }

    double expected[] = {4, 2, 3};
    if (arrays_equal(result, expected, len)) {
        printf("Test PASSED\n");
    } else {
        printf("Test FAILED\n");
        printf("Expected: ");
        for (size_t i = 0; i < len; i++) printf("%g ", expected[i]);
        printf("\nGot:      ");
        for (size_t i = 0; i < len; i++) printf("%g ", result[i]);
        printf("\n");
    }

    free(result);
    return 0;
}
