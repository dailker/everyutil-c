#include <stdio.h>
#include <math.h>
#include "color/contrast_ratio.h"

int main(void) {
    double ratio;
    
    // Test black vs white (should be ~21)
    ratio = contrast_ratio("#000000", "#ffffff");
    if (ratio > 20.0 && ratio < 22.0) {
        printf("black vs white: PASSED\n");
    } else {
        printf("black vs white: FAILED (got %.2f)\n", ratio);
    }
    
    // Test same colors (should be 1.0)
    ratio = contrast_ratio("#336699", "#336699");
    if (fabs(ratio - 1.0) < 0.1) {
        printf("same colors: PASSED\n");
    } else {
        printf("same colors: FAILED (got %.2f)\n", ratio);
    }
    
    // Test NULL input
    ratio = contrast_ratio(NULL, "#ffffff");
    if (ratio < 0) {
        printf("null input: PASSED\n");
    } else {
        printf("null input: FAILED\n");
    }
    
    return 0;
}