#include <stdio.h>
#include "logic/when.h"

int is_positive(int x) { return x > 0; }
int double_val(int x) { return x * 2; }

int main(void) {
    printf("When 5: %s\n", when(5, is_positive, double_val) == 10 ? "PASSED" : "FAILED");
    printf("When -3: %s\n", when(-3, is_positive, double_val) == -3 ? "PASSED" : "FAILED");
    
    return 0;
}