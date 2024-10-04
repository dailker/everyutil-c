#include <stdio.h>
#include "logic/negate.h"

int is_positive(int x) { return x > 0; }

int main(void) {
    printf("Negate 5: %s\n", negate(5, is_positive) == 0 ? "PASSED" : "FAILED");
    printf("Negate -3: %s\n", negate(-3, is_positive) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}