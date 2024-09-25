#include <stdio.h>
#include "color/hex_to_rgb.h"

int main(void) {
    RGB rgb;
    
    // Test valid hex color
    if (hex_to_rgb("#336699", &rgb) && rgb.r == 51 && rgb.g == 102 && rgb.b == 153) {
        printf("valid hex: PASSED\n");
    } else {
        printf("valid hex: FAILED\n");
    }
    
    // Test invalid hex color
    if (!hex_to_rgb("#gghhii", &rgb)) {
        printf("invalid hex: PASSED\n");
    } else {
        printf("invalid hex: FAILED\n");
    }
    
    // Test NULL input
    if (!hex_to_rgb(NULL, &rgb)) {
        printf("null input: PASSED\n");
    } else {
        printf("null input: FAILED\n");
    }
    
    // Test wrong length
    if (!hex_to_rgb("#fff", &rgb)) {
        printf("wrong length: PASSED\n");
    } else {
        printf("wrong length: FAILED\n");
    }
    
    return 0;
}