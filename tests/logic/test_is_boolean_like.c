#include <stdio.h>
#include "logic/is_boolean_like.h"

int main(void) {
    printf("Is boolean like 'true': %s\n", is_boolean_like("true") == 1 ? "PASSED" : "FAILED");
    printf("Is boolean like 'false': %s\n", is_boolean_like("false") == 1 ? "PASSED" : "FAILED");
    printf("Is boolean like '1': %s\n", is_boolean_like("1") == 1 ? "PASSED" : "FAILED");
    printf("Is boolean like '0': %s\n", is_boolean_like("0") == 1 ? "PASSED" : "FAILED");
    printf("Is boolean like 'hello': %s\n", is_boolean_like("hello") == 0 ? "PASSED" : "FAILED");
    
    return 0;
}