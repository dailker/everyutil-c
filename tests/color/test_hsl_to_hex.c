#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/hsl_to_hex.h"

int main(void) {
    char *result;
    
    // Test red color (H=0, S=100, L=50)
    result = hsl_to_hex(0.0, 100.0, 50.0);
    if (result && strcmp(result, "#ff0000") == 0) {
        printf("red color: PASSED\n");
    } else {
        printf("red color: FAILED (got %s)\n", result ? result : "NULL");
    }
    free(result);
    
    // Test white color (H=0, S=0, L=100)
    result = hsl_to_hex(0.0, 0.0, 100.0);
    if (result && strcmp(result, "#ffffff") == 0) {
        printf("white color: PASSED\n");
    } else {
        printf("white color: FAILED (got %s)\n", result ? result : "NULL");
    }
    free(result);
    
    // Test black color (H=0, S=0, L=0)
    result = hsl_to_hex(0.0, 0.0, 0.0);
    if (result && strcmp(result, "#000000") == 0) {
        printf("black color: PASSED\n");
    } else {
        printf("black color: FAILED (got %s)\n", result ? result : "NULL");
    }
    free(result);
    
    // Test blue color (H=240, S=100, L=50)
    result = hsl_to_hex(240.0, 100.0, 50.0);
    if (result && strcmp(result, "#0000ff") == 0) {
        printf("blue color: PASSED\n");
    } else {
        printf("blue color: FAILED (got %s)\n", result ? result : "NULL");
    }
    free(result);
    
    return 0;
}