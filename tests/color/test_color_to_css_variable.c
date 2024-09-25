#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/color_to_css_variable.h"

int main(void) {
    char *result;
    
    // Test basic CSS variable
    result = color_to_css_variable("#336699", "--main-color");
    if (result && strcmp(result, "--main-color: #336699;") == 0) {
        printf("basic css variable: PASSED\n");
    } else {
        printf("basic css variable: FAILED (got '%s')\n", result ? result : "NULL");
    }
    free(result);
    
    // Test with NULL inputs
    result = color_to_css_variable(NULL, "--color");
    if (result == NULL) {
        printf("null color: PASSED\n");
    } else {
        printf("null color: FAILED\n");
        free(result);
    }
    
    result = color_to_css_variable("#fff", NULL);
    if (result == NULL) {
        printf("null variable name: PASSED\n");
    } else {
        printf("null variable name: FAILED\n");
        free(result);
    }
    
    return 0;
}