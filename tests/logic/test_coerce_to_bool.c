#include <stdio.h>
#include "logic/coerce_to_bool.h"

int main(void) {
    printf("Coerce 'true' strict: %s\n", coerce_to_bool("true", 1) == 1 ? "PASSED" : "FAILED");
    printf("Coerce 'false' strict: %s\n", coerce_to_bool("false", 1) == 0 ? "PASSED" : "FAILED");
    printf("Coerce '1' strict: %s\n", coerce_to_bool("1", 1) == 1 ? "PASSED" : "FAILED");
    printf("Coerce 'hello' non-strict: %s\n", coerce_to_bool("hello", 0) == 1 ? "PASSED" : "FAILED");
    printf("Coerce '0' non-strict: %s\n", coerce_to_bool("0", 0) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}