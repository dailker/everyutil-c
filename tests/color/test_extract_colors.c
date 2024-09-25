#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/extract_colors.h"

int main(void) {
    char **colors;
    size_t count;
    
    // Test CSS with hex colors
    colors = extractColorsFromCss("body { color: #336699; background: #ffffff; }", &count);
    if (colors && count == 2 && 
        strcmp(colors[0], "#336699") == 0 &&
        strcmp(colors[1], "#ffffff") == 0) {
        printf("extract hex colors: PASSED\n");
    } else {
        printf("extract hex colors: FAILED (count: %zu)\n", count);
    }
    if (colors) {
        for (size_t i = 0; i < count; i++) free(colors[i]);
        free(colors);
    }
    
    // Test CSS with rgb colors
    colors = extractColorsFromCss("div { color: rgb(255,128,64); }", &count);
    if (colors && count == 1 && strcmp(colors[0], "rgb(255,128,64)") == 0) {
        printf("extract rgb colors: PASSED\n");
    } else {
        printf("extract rgb colors: FAILED\n");
    }
    if (colors) {
        for (size_t i = 0; i < count; i++) free(colors[i]);
        free(colors);
    }
    
    // Test empty CSS
    colors = extractColorsFromCss("body { font-size: 12px; }", &count);
    if (colors == NULL && count == 0) {
        printf("no colors: PASSED\n");
    } else {
        printf("no colors: FAILED\n");
        if (colors) {
            for (size_t i = 0; i < count; i++) free(colors[i]);
            free(colors);
        }
    }
    
    return 0;
}