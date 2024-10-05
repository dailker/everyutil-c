#include <stdio.h>
#include "logic/ternary_logic_table.h"

int main(void) {
    printf("Ternary unknown: %s\n", ternary_logic_table(0, 0, 1) == TERNARY_UNKNOWN ? "PASSED" : "FAILED");
    printf("Ternary true: %s\n", ternary_logic_table(1, 0, 0) == TERNARY_TRUE ? "PASSED" : "FAILED");
    printf("Ternary false: %s\n", ternary_logic_table(0, 1, 0) == TERNARY_FALSE ? "PASSED" : "FAILED");
    printf("Ternary indeterminate: %s\n", ternary_logic_table(0, 0, 0) == TERNARY_INDETERMINATE ? "PASSED" : "FAILED");
    
    return 0;
}