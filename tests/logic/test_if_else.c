#include <stdio.h>
#include "logic/if_else.h"

int is_positive(int x) { return x > 0; }
int double_val(int x) { return x * 2; }
int negate_val(int x) { return -x; }

int main(void) {
    printf("If else 5: %s\n", if_else(5, is_positive, double_val, negate_val) == 10 ? "PASSED" : "FAILED");
    printf("If else -3: %s\n", if_else(-3, is_positive, double_val, negate_val) == 3 ? "PASSED" : "FAILED");
    
    return 0;
}