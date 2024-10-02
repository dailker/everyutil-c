#include <stdio.h>
#include "logic/fuzzy_bool.h"

int main(void) {
    printf("Fuzzy bool 0.7 >= 0.5: %s\n", fuzzy_bool(0.7, 0.5) == 1 ? "PASSED" : "FAILED");
    printf("Fuzzy bool 0.3 >= 0.5: %s\n", fuzzy_bool(0.3, 0.5) == 0 ? "PASSED" : "FAILED");
    
    return 0;
}