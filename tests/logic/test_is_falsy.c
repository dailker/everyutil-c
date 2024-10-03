#include <stdio.h>
#include "logic/is_falsy.h"

int main(void) {
    printf("Is falsy 0: %s\n", is_falsy(0) == 1 ? "PASSED" : "FAILED");
    printf("Is falsy 1: %s\n", is_falsy(1) == 0 ? "PASSED" : "FAILED");
    printf("Is falsy -1: %s\n", is_falsy(-1) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}