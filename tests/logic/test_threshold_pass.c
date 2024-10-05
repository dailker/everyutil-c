#include <stdio.h>
#include "logic/threshold_pass.h"

int main(void) {
    int values[] = {1, 0, 1, 1, 0};  // 3 true values
    
    printf("Threshold pass 2: %s\n", threshold_pass(2, values, 5) == 1 ? "PASSED" : "FAILED");
    printf("Threshold pass 3: %s\n", threshold_pass(3, values, 5) == 1 ? "PASSED" : "FAILED");
    printf("Threshold pass 4: %s\n", threshold_pass(4, values, 5) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}