#include <stdio.h>
#include "logic/is_not_nil.h"

int main(void) {
    int val = 5;
    printf("Is not nil NULL: %s\n", is_not_nil(NULL) == 0 ? "PASSED" : "FAILED");
    printf("Is not nil &val: %s\n", is_not_nil(&val) == 1 ? "PASSED" : "FAILED");
    
    return 0;
}