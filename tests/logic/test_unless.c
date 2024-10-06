#include <stdio.h>
#include "logic/unless.h"

int is_positive(int x) { return x > 0; }
int double_val(int x) { return x * 2; }

int main(void) {
    printf("Unless 5: %s\n", unless(5, is_positive, double_val) == 5 ? "PASSED" : "FAILED");
    printf("Unless -3: %s\n", unless(-3, is_positive, double_val) == -6 ? "PASSED" : "FAILED");
    
    return 0;
}