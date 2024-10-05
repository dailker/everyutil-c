#include <stdio.h>
#include "logic/select_first_passing.h"

static int is_positive(int x) {
    return x > 0;
}

static int is_even(int x) {
    return x % 2 == 0;
}

int main(void) {
    int items[] = {-1, 0, 3, 4, 5};
    
    int first_positive = select_first_passing(items, 5, is_positive);
    int first_even = select_first_passing(items, 5, is_even);
    
    printf("First positive index: %s (got %d)\n", first_positive == 2 ? "PASSED" : "FAILED", first_positive);
    printf("First even index: %s (got %d)\n", first_even == 1 ? "PASSED" : "FAILED", first_even);
    
    return 0;
}