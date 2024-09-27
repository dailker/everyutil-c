#include <stdio.h>
#include "logic/all_same.h"

int main(void) {
    int all_true[] = {1, 1, 1};
    int all_false[] = {0, 0, 0};
    int mixed[] = {1, 0, 1};
    
    printf("All same true: %s\n", all_same(all_true, 3) == 1 ? "PASSED" : "FAILED");
    printf("All same false: %s\n", all_same(all_false, 3) == 1 ? "PASSED" : "FAILED");
    printf("All same mixed: %s\n", all_same(mixed, 3) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}