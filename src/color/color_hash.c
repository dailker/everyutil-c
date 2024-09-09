#include "color/color_hash.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

static char *rgb_to_hex(int r, int g, int b) {
    char *result = (char *)malloc(8);
    if (!result) return NULL;
    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;
    sprintf(result, "#%02x%02x%02x", r, g, b);
    return result;
}

EVERYUTIL_API char *color_hash(const char *inputString) {
    if (!inputString) return NULL;

    uint32_t hash = 5381;
    const char *p = inputString;
    
    while (*p) {
        hash = ((hash << 5) + hash) + *p++;
    }

    int r = (hash >> 16) & 0xFF;
    int g = (hash >> 8) & 0xFF;
    int b = hash & 0xFF;

    return rgb_to_hex(r, g, b);
}