#include <stdio.h>
#include "logic/weighted_bool.h"

int main(void) {
    printf("Weighted bool 0.7 >= 0.5: %s\n", weighted_bool(0.7, 0.5) == 1 ? "PASSED" : "FAILED");
    printf("Weighted bool 0.3 >= 0.5: %s\n", weighted_bool(0.3, 0.5) == 0 ? "PASSED" : "FAILED");
    printf("Weighted bool 0.8 >= 0.8: %s\n", weighted_bool(0.8, 0.8) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}