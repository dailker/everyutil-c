#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/color_to_css.h"

int main(void) {
    char *result;
    
    // Test RGB without alpha
    result = color_to_css(255, 128, 64, -1.0);
    if (result && strcmp(result, "rgb(255,128,64)") == 0) {
        printf("rgb without alpha: PASSED\n");
    } else {
        printf("rgb without alpha: FAILED\n");
    }
    free(result);
    
    // Test RGBA with alpha
    result = color_to_css(255, 128, 64, 0.5);
    if (result && strcmp(result, "rgba(255,128,64,0.5)") == 0) {
        printf("rgba with alpha: PASSED\n");
    } else {
        printf("rgba with alpha: FAILED\n");
    }
    free(result);
    
    // Test clamping
    result = color_to_css(300, -10, 64, 1.0);
    if (result && strcmp(result, "rgb(255,0,64)") == 0) {
        printf("clamping: PASSED\n");
    } else {
        printf("clamping: FAILED\n");
    }
    free(result);
    
    return 0;
}