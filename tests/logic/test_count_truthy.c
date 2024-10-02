#include <stdio.h>
#include "logic/count_truthy.h"

int main(void) {
    int values[] = {1, 0, -1, 2, 0};
    
    printf("Count truthy test: %s\n", count_truthy(values, 5) == 3 ? "PASSED" : "FAILED");
    
    return 0;
}