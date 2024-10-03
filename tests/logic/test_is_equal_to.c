#include <stdio.h>
#include "logic/is_equal_to.h"

int main(void) {
    printf("Is equal to 5,5: %s\n", is_equal_to(5, 5) == 1 ? "PASSED" : "FAILED");
    printf("Is equal to 5,3: %s\n", is_equal_to(5, 3) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}