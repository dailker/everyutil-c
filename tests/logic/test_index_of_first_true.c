#include <stdio.h>
#include "logic/index_of_first_true.h"

int main(void) {
    int array1[] = {0, 0, 1, 0, 1};
    int array2[] = {0, 0, 0};
    int array3[] = {1, 0, 0};
    
    printf("First true at index 2 test: %s\n", index_of_first_true(array1, 5) == 2 ? "PASSED" : "FAILED");
    printf("No true values test: %s\n", index_of_first_true(array2, 3) == -1 ? "PASSED" : "FAILED");
    printf("First true at index 0 test: %s\n", index_of_first_true(array3, 3) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}