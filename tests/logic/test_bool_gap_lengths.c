#include <stdio.h>
#include "logic/bool_gap_lengths.h"

int main(void) {
    int array[] = {1, 1, 0, 0, 1, 0, 1, 1};  // gaps: [2, 1]
    int gaps[10];
    
    int count = bool_gap_lengths(array, 8, gaps, 10);
    
    printf("Gap count: %s (got %d, expected 2)\n", count == 2 ? "PASSED" : "FAILED", count);
    if (count >= 2) {
        printf("First gap: %s (got %d, expected 2)\n", gaps[0] == 2 ? "PASSED" : "FAILED", gaps[0]);
        printf("Second gap: %s (got %d, expected 1)\n", gaps[1] == 1 ? "PASSED" : "FAILED", gaps[1]);
    }
    
    return 0;
}