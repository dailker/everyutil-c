#include <stdio.h>
#include "logic/boolean_consensus.h"

int main(void) {
    int all_true[] = {1, 1, 1};
    int all_false[] = {0, 0, 0};
    int mixed[] = {1, 0, 1};
    
    printf("Boolean consensus all true: %s\n", boolean_consensus(all_true, 3) == 1 ? "PASSED" : "FAILED");
    printf("Boolean consensus all false: %s\n", boolean_consensus(all_false, 3) == 1 ? "PASSED" : "FAILED");
    printf("Boolean consensus mixed: %s\n", boolean_consensus(mixed, 3) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}