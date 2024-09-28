#include <stdio.h>
#include "logic/biconditional.h"

int main(void) {
    printf("Biconditional 1,1: %s\n", biconditional(1, 1) == 1 ? "PASSED" : "FAILED");
    printf("Biconditional 0,0: %s\n", biconditional(0, 0) == 1 ? "PASSED" : "FAILED");
    printf("Biconditional 1,0: %s\n", biconditional(1, 0) == 0 ? "PASSED" : "FAILED");
    printf("Biconditional 0,1: %s\n", biconditional(0, 1) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}