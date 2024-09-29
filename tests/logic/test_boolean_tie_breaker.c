#include <stdio.h>
#include "logic/boolean_tie_breaker.h"

int main(void) {
    printf("Tie breaker both false, backup true: %s\n", 
           boolean_tie_breaker(0, 0, 1) == 1 ? "PASSED" : "FAILED");
    printf("Tie breaker both true, backup false: %s\n", 
           boolean_tie_breaker(1, 1, 0) == 0 ? "PASSED" : "FAILED");
    printf("Tie breaker different values: %s\n", 
           boolean_tie_breaker(1, 0, 0) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}