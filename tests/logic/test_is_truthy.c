#include <stdio.h>
#include "logic/is_truthy.h"

int main(void) {
    printf("Is truthy 1: %s\n", is_truthy(1) == 1 ? "PASSED" : "FAILED");
    printf("Is truthy 0: %s\n", is_truthy(0) == 0 ? "PASSED" : "FAILED");
    printf("Is truthy -1: %s\n", is_truthy(-1) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}