#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic/bool_by_probability.h"

int main(void) {
    srand((unsigned int)time(NULL));
    
    printf("Bool by probability 0.0: %s\n", bool_by_probability(0.0) == 0 ? "PASSED" : "FAILED");
    printf("Bool by probability 1.0: %s\n", bool_by_probability(1.0) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}