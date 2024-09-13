#include "color/rgb_to_hex.h"
#include <stdio.h>
#include <stdlib.h>
EVERYUTIL_API char *rgb_to_hex(int r, int g, int b) {
    char *str = (char *)malloc(8);
    if (!str) return NULL;
    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;
    sprintf(str, "#%02x%02x%02x", r, g, b);
    return str;
}