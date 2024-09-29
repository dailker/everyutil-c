#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic/boolean_by_entropy.h"

int main(void) {
    srand((unsigned int)time(NULL));
    
    printf("Boolean by entropy 0.0: %s\n", boolean_by_entropy(0.0) == 0 ? "PASSED" : "FAILED");
    printf("Boolean by entropy 1.0: %s\n", boolean_by_entropy(1.0) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}