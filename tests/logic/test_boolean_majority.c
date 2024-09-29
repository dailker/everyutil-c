#include <stdio.h>
#include "logic/boolean_majority.h"

int main(void) {
    int flags1[] = {1, 1, 0};  // 2/3 true
    int flags2[] = {1, 0, 0};  // 1/3 true
    int flags3[] = {1, 1, 1, 0, 0};  // 3/5 true
    
    printf("Majority 2/3 test: %s\n", boolean_majority(flags1, 3) == 1 ? "PASSED" : "FAILED");
    printf("Majority 1/3 test: %s\n", boolean_majority(flags2, 3) == 0 ? "PASSED" : "FAILED");
    printf("Majority 3/5 test: %s\n", boolean_majority(flags3, 5) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}