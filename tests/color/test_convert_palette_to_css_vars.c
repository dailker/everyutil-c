#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/convert_palette_to_css_vars.h"

int main(void) {
    const char *palette[] = {"#ff0000", "#00ff00", "#0000ff"};
    char *result;
    
    // Test basic palette conversion
    result = convert_palette_to_css_vars(palette, 3, "--color");
    if (result && strstr(result, ":root {") && 
        strstr(result, "--color-0: #ff0000;") &&
        strstr(result, "--color-1: #00ff00;") &&
        strstr(result, "--color-2: #0000ff;") &&
        strstr(result, "}")) {
        printf("basic palette: PASSED\n");
    } else {
        printf("basic palette: FAILED\n");
    }
    free(result);
    
    // Test NULL palette
    result = convert_palette_to_css_vars(NULL, 3, "--color");
    if (result == NULL) {
        printf("null palette: PASSED\n");
    } else {
        printf("null palette: FAILED\n");
        free(result);
    }
    
    // Test NULL prefix
    result = convert_palette_to_css_vars(palette, 3, NULL);
    if (result == NULL) {
        printf("null prefix: PASSED\n");
    } else {
        printf("null prefix: FAILED\n");
        free(result);
    }
    
    return 0;
}