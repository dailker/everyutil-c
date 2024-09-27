#include <stdio.h>
#include "logic/any_pass.h"

int is_positive(int x) { return x > 0; }
int is_even(int x) { return x % 2 == 0; }

int main(void) {
    predicate_func preds[] = {is_positive, is_even};
    
    printf("Any pass 3: %s\n", any_pass(3, preds, 2) == 1 ? "PASSED" : "FAILED");
    printf("Any pass -1: %s\n", any_pass(-1, preds, 2) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}