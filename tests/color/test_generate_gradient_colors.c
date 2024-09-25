#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/generate_gradient_colors.h"

int main(void) {
    char **gradient;
    
    // Test basic gradient
    gradient = generate_gradient_colors("#000000", "#ffffff", 3);
    if (gradient && 
        strcmp(gradient[0], "#000000") == 0 &&
        strcmp(gradient[1], "#808080") == 0 &&
        strcmp(gradient[2], "#FFFFFF") == 0) {
        printf("basic gradient: PASSED\n");
    } else {
        printf("basic gradient: FAILED\n");
    }
    if (gradient) {
        for (int i = 0; i < 3; i++) free(gradient[i]);
        free(gradient);
    }
    
    // Test invalid inputs
    gradient = generate_gradient_colors(NULL, "#ffffff", 3);
    if (gradient == NULL) {
        printf("null start: PASSED\n");
    } else {
        printf("null start: FAILED\n");
        for (int i = 0; i < 3; i++) free(gradient[i]);
        free(gradient);
    }
    
    gradient = generate_gradient_colors("#000000", "#ffffff", 1);
    if (gradient == NULL) {
        printf("invalid steps: PASSED\n");
    } else {
        printf("invalid steps: FAILED\n");
        free(gradient[0]);
        free(gradient);
    }
    
    return 0;
}