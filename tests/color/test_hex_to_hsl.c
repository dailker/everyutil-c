#include <stdio.h>
#include <math.h>
#include "color/hex_to_hsl.h"

int main(void) {
    HSL hsl;
    
    // Test red color
    if (hex_to_hsl("#ff0000", &hsl) && 
        fabs(hsl.h - 0.0) < 1.0 && 
        fabs(hsl.s - 100.0) < 1.0 && 
        fabs(hsl.l - 50.0) < 1.0) {
        printf("red color: PASSED\n");
    } else {
        printf("red color: FAILED (h:%.1f s:%.1f l:%.1f)\n", hsl.h, hsl.s, hsl.l);
    }
    
    // Test white color
    if (hex_to_hsl("#ffffff", &hsl) && 
        fabs(hsl.s - 0.0) < 1.0 && 
        fabs(hsl.l - 100.0) < 1.0) {
        printf("white color: PASSED\n");
    } else {
        printf("white color: FAILED\n");
    }
    
    // Test black color
    if (hex_to_hsl("#000000", &hsl) && 
        fabs(hsl.s - 0.0) < 1.0 && 
        fabs(hsl.l - 0.0) < 1.0) {
        printf("black color: PASSED\n");
    } else {
        printf("black color: FAILED\n");
    }
    
    // Test invalid input
    if (!hex_to_hsl("invalid", &hsl)) {
        printf("invalid input: PASSED\n");
    } else {
        printf("invalid input: FAILED\n");
    }
    
    return 0;
}