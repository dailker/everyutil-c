#include <stdio.h>
#include <math.h>
#include "logic/score_conditions.h"

int main(void) {
    double weights[] = {1.5, 2.0, 0.5};
    int conditions[] = {1, 0, 1};  // first and third are true
    
    double score = score_conditions(weights, conditions, 3);
    double expected = 1.5 + 0.5; // 2.0
    
    printf("Score conditions test: %s (got %.1f, expected %.1f)\n", 
           fabs(score - expected) < 0.01 ? "PASSED" : "FAILED", score, expected);
    
    return 0;
}