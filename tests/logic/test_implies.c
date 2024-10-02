#include <stdio.h>
#include "logic/implies.h"

int main(void) {
    printf("Implies 0,0 test: %s\n", implies(0, 0) == 1 ? "PASSED" : "FAILED");
    printf("Implies 0,1 test: %s\n", implies(0, 1) == 1 ? "PASSED" : "FAILED");
    printf("Implies 1,0 test: %s\n", implies(1, 0) == 0 ? "PASSED" : "FAILED");
    printf("Implies 1,1 test: %s\n", implies(1, 1) == 1 ? "PASSED" : "FAILED");
    return 0;
}