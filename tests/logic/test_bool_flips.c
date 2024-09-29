#include <stdio.h>
#include "logic/bool_flips.h"

int main(void) {
    int array1[] = {1, 0, 1, 0};  // 3 flips
    int array2[] = {1, 1, 1, 1};  // 0 flips
    int array3[] = {0, 1};        // 1 flip
    
    printf("Bool flips 3 test: %s\n", bool_flips(array1, 4) == 3 ? "PASSED" : "FAILED");
    printf("Bool flips 0 test: %s\n", bool_flips(array2, 4) == 0 ? "PASSED" : "FAILED");
    printf("Bool flips 1 test: %s\n", bool_flips(array3, 2) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}