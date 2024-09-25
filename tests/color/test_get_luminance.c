#include <stdio.h>
#include <math.h>
#include "color/get_luminance.h"

int main(void) {
    double luminance;
    
    // Test white (should be close to 1.0)
    luminance = get_luminance("#ffffff");
    if (fabs(luminance - 1.0) < 0.01) {
        printf("white luminance: PASSED\n");
    } else {
        printf("white luminance: FAILED (got %.3f)\n", luminance);
    }
    
    // Test black (should be close to 0.0)
    luminance = get_luminance("#000000");
    if (fabs(luminance - 0.0) < 0.01) {
        printf("black luminance: PASSED\n");
    } else {
        printf("black luminance: FAILED (got %.3f)\n", luminance);
    }
    
    // Test red
    luminance = get_luminance("#ff0000");
    if (luminance > 0.1 && luminance < 0.3) {
        printf("red luminance: PASSED\n");
    } else {
        printf("red luminance: FAILED (got %.3f)\n", luminance);
    }
    
    // Test RGB format
    luminance = get_luminance("rgb(255,255,255)");
    if (fabs(luminance - 1.0) < 0.01) {
        printf("rgb white luminance: PASSED\n");
    } else {
        printf("rgb white luminance: FAILED (got %.3f)\n", luminance);
    }
    
    // Test invalid input
    luminance = get_luminance("invalid");
    if (fabs(luminance - 0.0) < 0.01) {
        printf("invalid input: PASSED\n");
    } else {
        printf("invalid input: FAILED\n");
    }
    
    return 0;
}