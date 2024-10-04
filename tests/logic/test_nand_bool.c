#include <stdio.h>
#include "logic/nand_bool.h"

int main(void) {
    printf("NAND 0,0 test: %s\n", nand_bool(0, 0) == 1 ? "PASSED" : "FAILED");
    printf("NAND 0,1 test: %s\n", nand_bool(0, 1) == 1 ? "PASSED" : "FAILED");
    printf("NAND 1,0 test: %s\n", nand_bool(1, 0) == 1 ? "PASSED" : "FAILED");
    printf("NAND 1,1 test: %s\n", nand_bool(1, 1) == 0 ? "PASSED" : "FAILED");
    return 0;
}