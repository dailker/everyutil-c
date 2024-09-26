#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/extract_dominant_colors.h"

int main(void) {
    // Create simple test image data (2x2 pixels, RGB)
    unsigned char image_data[] = {
        255, 0, 0,    // Red pixel
        255, 0, 0,    // Red pixel
        0, 255, 0,    // Green pixel
        0, 0, 255     // Blue pixel
    };
    
    char **colors;
    
    // Test extracting 2 dominant colors
    colors = extract_dominant_colors(image_data, 2, 2, 2);
    if (colors && colors[0] && colors[1] && colors[2] == NULL) {
        printf("extract 2 colors: PASSED\n");
    } else {
        printf("extract 2 colors: FAILED\n");
    }
    if (colors) {
        for (int i = 0; colors[i]; i++) free(colors[i]);
        free(colors);
    }
    
    // Test NULL data
    colors = extract_dominant_colors(NULL, 2, 2, 2);
    if (colors == NULL) {
        printf("null data: PASSED\n");
    } else {
        printf("null data: FAILED\n");
        for (int i = 0; colors[i]; i++) free(colors[i]);
        free(colors);
    }
    
    // Test zero dimensions
    colors = extract_dominant_colors(image_data, 0, 2, 2);
    if (colors == NULL) {
        printf("zero width: PASSED\n");
    } else {
        printf("zero width: FAILED\n");
        for (int i = 0; colors[i]; i++) free(colors[i]);
        free(colors);
    }
    
    // Test zero count
    colors = extract_dominant_colors(image_data, 2, 2, 0);
    if (colors == NULL) {
        printf("zero count: PASSED\n");
    } else {
        printf("zero count: FAILED\n");
        for (int i = 0; colors[i]; i++) free(colors[i]);
        free(colors);
    }
    
    return 0;
}