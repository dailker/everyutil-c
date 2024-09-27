#include <stdio.h>
#include "logic/and_all.h"

int main(void) {
    int all_true[] = {1, 1, 1};
    int mixed[] = {1, 0, 1};
    
    printf("And all true test: %s\n", and_all(all_true, 3) == 1 ? "PASSED" : "FAILED");
    printf("And mixed test: %s\n", and_all(mixed, 3) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}