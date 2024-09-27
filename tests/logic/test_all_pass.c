#include <stdio.h>
#include "logic/all_pass.h"

int is_positive(int x) { return x > 0; }
int is_even(int x) { return x % 2 == 0; }

int main(void) {
    predicate_func preds[] = {is_positive, is_even};
    
    printf("All pass 4: %s\n", all_pass(4, preds, 2) == 1 ? "PASSED" : "FAILED");
    printf("All pass 3: %s\n", all_pass(3, preds, 2) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}