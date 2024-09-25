#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/create_striped_pattern.h"

int main(void) {
    const char *colors[] = {"#ff0000", "#00ff00", "#0000ff"};
    char **pattern;
    size_t size;
    
    // Test basic striped pattern
    pattern = create_striped_pattern(colors, 3, 2, &size);
    if (pattern && size == 6 &&
        strcmp(pattern[0], "#ff0000") == 0 &&
        strcmp(pattern[1], "#ff0000") == 0 &&
        strcmp(pattern[2], "#00ff00") == 0 &&
        strcmp(pattern[3], "#00ff00") == 0 &&
        strcmp(pattern[4], "#0000ff") == 0 &&
        strcmp(pattern[5], "#0000ff") == 0) {
        printf("basic striped pattern: PASSED\n");
    } else {
        printf("basic striped pattern: FAILED (size: %zu)\n", size);
    }
    if (pattern) {
        free_striped_pattern(pattern, size);
    }
    
    // Test NULL colors
    pattern = create_striped_pattern(NULL, 3, 2, &size);
    if (pattern == NULL) {
        printf("null colors: PASSED\n");
    } else {
        printf("null colors: FAILED\n");
        free_striped_pattern(pattern, size);
    }
    
    // Test zero width
    pattern = create_striped_pattern(colors, 3, 0, &size);
    if (pattern == NULL) {
        printf("zero width: PASSED\n");
    } else {
        printf("zero width: FAILED\n");
        free_striped_pattern(pattern, size);
    }
    
    return 0;
}