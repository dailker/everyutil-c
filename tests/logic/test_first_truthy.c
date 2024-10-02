#include <stdio.h>
#include "logic/first_truthy.h"

int main(void) {
    int values[] = {0, 0, 5, 3};
    
    printf("First truthy: %s\n", first_truthy(values, 4) == 5 ? "PASSED" : "FAILED");
    
    return 0;
}