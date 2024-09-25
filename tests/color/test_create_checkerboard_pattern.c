#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/create_checkerboard_pattern.h"

int main(void) {
    char ***pattern;
    
    // Test 2x2 checkerboard
    pattern = create_checkerboard_pattern("#000000", "#ffffff", 2);
    if (pattern && 
        strcmp(pattern[0][0], "#000000") == 0 &&
        strcmp(pattern[0][1], "#ffffff") == 0 &&
        strcmp(pattern[1][0], "#ffffff") == 0 &&
        strcmp(pattern[1][1], "#000000") == 0) {
        printf("2x2 checkerboard: PASSED\n");
    } else {
        printf("2x2 checkerboard: FAILED\n");
    }
    if (pattern) {
        free_checkerboard_pattern(pattern, 2);
    }
    
    // Test NULL inputs
    pattern = create_checkerboard_pattern(NULL, "#ffffff", 2);
    if (pattern == NULL) {
        printf("null color1: PASSED\n");
    } else {
        printf("null color1: FAILED\n");
        free_checkerboard_pattern(pattern, 2);
    }
    
    pattern = create_checkerboard_pattern("#000000", NULL, 2);
    if (pattern == NULL) {
        printf("null color2: PASSED\n");
    } else {
        printf("null color2: FAILED\n");
        free_checkerboard_pattern(pattern, 2);
    }
    
    // Test zero size
    pattern = create_checkerboard_pattern("#000000", "#ffffff", 0);
    if (pattern == NULL) {
        printf("zero size: PASSED\n");
    } else {
        printf("zero size: FAILED\n");
        free_checkerboard_pattern(pattern, 0);
    }
    
    return 0;
}