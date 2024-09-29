#include <stdio.h>
#include <math.h>
#include "logic/boolean_weighted_average.h"

int main(void) {
    int results[] = {1, 0, 1};
    double weights[] = {0.5, 0.3, 0.2};
    
    double avg = boolean_weighted_average(results, weights, 3);
    double expected = (0.5 + 0.2) / (0.5 + 0.3 + 0.2); // 0.7
    
    printf("Boolean weighted average test: %s (got %.2f, expected %.2f)\n", 
           fabs(avg - expected) < 0.01 ? "PASSED" : "FAILED", avg, expected);
    
    return 0;
}