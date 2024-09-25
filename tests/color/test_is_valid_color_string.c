#include <stdio.h>
#include "color/is_valid_color_string.h"

int main(void) {
    // Test valid hex colors
    if (is_valid_color_string("#336699")) {
        printf("valid hex #336699: PASSED\n");
    } else {
        printf("valid hex #336699: FAILED\n");
    }
    
    if (is_valid_color_string("#fff")) {
        printf("valid hex #fff: PASSED\n");
    } else {
        printf("valid hex #fff: FAILED\n");
    }
    
    // Test valid rgb
    if (is_valid_color_string("rgb(255,128,64)")) {
        printf("valid rgb: PASSED\n");
    } else {
        printf("valid rgb: FAILED\n");
    }
    
    // Test valid rgba
    if (is_valid_color_string("rgba(255,128,64,0.5)")) {
        printf("valid rgba: PASSED\n");
    } else {
        printf("valid rgba: FAILED\n");
    }
    
    // Test invalid colors
    if (!is_valid_color_string("#gghhii")) {
        printf("invalid hex: PASSED\n");
    } else {
        printf("invalid hex: FAILED\n");
    }
    
    if (!is_valid_color_string("rgb(300,128,64)")) {
        printf("invalid rgb range: PASSED\n");
    } else {
        printf("invalid rgb range: FAILED\n");
    }
    
    // Test NULL
    if (!is_valid_color_string(NULL)) {
        printf("null input: PASSED\n");
    } else {
        printf("null input: FAILED\n");
    }
    
    return 0;
}