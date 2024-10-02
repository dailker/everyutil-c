#include <stdio.h>
#include "logic/invert_boolean_array.h"

int main(void) {
    int array[] = {1, 0, 1, 0};
    invert_boolean_array(array, 4);
    
    printf("Invert array test: %s\n", 
           (array[0] == 0 && array[1] == 1 && array[2] == 0 && array[3] == 1) ? "PASSED" : "FAILED");
    
    return 0;
}