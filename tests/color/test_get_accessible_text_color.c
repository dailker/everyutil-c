#include <stdio.h>
#include <string.h>
#include "color/get_accessible_text_color.h"

int main(void) {
    const char *result;
    
    // Test dark background
    result = get_accessible_text_color("#000000");
    if (result && strcmp(result, "#fff") == 0) {
        printf("dark background: PASSED\n");
    } else {
        printf("dark background: FAILED\n");
    }
    
    // Test light background
    result = get_accessible_text_color("#ffffff");
    if (result && strcmp(result, "#000") == 0) {
        printf("light background: PASSED\n");
    } else {
        printf("light background: FAILED\n");
    }
    
    // Test medium color
    result = get_accessible_text_color("#808080");
    if (result && (strcmp(result, "#fff") == 0 || strcmp(result, "#000") == 0)) {
        printf("medium background: PASSED\n");
    } else {
        printf("medium background: FAILED\n");
    }
    
    // Test NULL input
    result = get_accessible_text_color(NULL);
    if (result == NULL) {
        printf("null input: PASSED\n");
    } else {
        printf("null input: FAILED\n");
    }
    
    return 0;
}