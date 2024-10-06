#include <stdio.h>
#include "logic/xor_bool.h"

int main(void) {
    printf("XOR 0,0 test: %s\n", xor_bool(0, 0) == 0 ? "PASSED" : "FAILED");
    printf("XOR 0,1 test: %s\n", xor_bool(0, 1) == 1 ? "PASSED" : "FAILED");
    printf("XOR 1,0 test: %s\n", xor_bool(1, 0) == 1 ? "PASSED" : "FAILED");
    printf("XOR 1,1 test: %s\n", xor_bool(1, 1) == 0 ? "PASSED" : "FAILED");
    return 0;
}