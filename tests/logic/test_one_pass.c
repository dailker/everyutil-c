#include <stdio.h>
#include "logic/one_pass.h"

int main(void) {
    int one_true[] = {0, 1, 0};
    int two_true[] = {1, 1, 0};
    int none_true[] = {0, 0, 0};
    
    printf("One pass exactly one: %s\n", one_pass(one_true, 3) == 1 ? "PASSED" : "FAILED");
    printf("One pass two true: %s\n", one_pass(two_true, 3) == 0 ? "PASSED" : "FAILED");
    printf("One pass none true: %s\n", one_pass(none_true, 3) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}