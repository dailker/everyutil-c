#include <stdio.h>
#include <math.h>
#include "logic/fuzzy_logic_gate.h"

int main(void) {
    double values[] = {0.3, 0.7, 0.5};
    
    double and_result = fuzzy_logic_gate(FUZZY_AND, values, 3);
    double or_result = fuzzy_logic_gate(FUZZY_OR, values, 3);
    double not_result = fuzzy_logic_gate(FUZZY_NOT, values, 1);
    
    printf("Fuzzy AND test: %s (got %.1f, expected 0.3)\n", 
           fabs(and_result - 0.3) < 0.01 ? "PASSED" : "FAILED", and_result);
    printf("Fuzzy OR test: %s (got %.1f, expected 0.7)\n", 
           fabs(or_result - 0.7) < 0.01 ? "PASSED" : "FAILED", or_result);
    printf("Fuzzy NOT test: %s (got %.1f, expected 0.7)\n", 
           fabs(not_result - 0.7) < 0.01 ? "PASSED" : "FAILED", not_result);
    
    return 0;
}