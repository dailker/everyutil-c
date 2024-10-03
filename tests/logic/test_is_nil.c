#include <stdio.h>
#include "logic/is_nil.h"

int main(void) {
    int val = 5;
    printf("Is nil NULL: %s\n", is_nil(NULL) == 1 ? "PASSED" : "FAILED");
    printf("Is nil &val: %s\n", is_nil(&val) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}