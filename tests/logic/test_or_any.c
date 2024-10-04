#include <stdio.h>
#include "logic/or_any.h"

int main(void) {
    int all_false[] = {0, 0, 0};
    int mixed[] = {0, 1, 0};
    
    printf("Or any false test: %s\n", or_any(all_false, 3) == 0 ? "PASSED" : "FAILED");
    printf("Or mixed test: %s\n", or_any(mixed, 3) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}