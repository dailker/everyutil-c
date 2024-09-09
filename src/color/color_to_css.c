#include "color/color_to_css.h"
#include <stdio.h>
#include <stdlib.h>

char *color_to_css(int r, int g, int b, double a) {
    // Clamp inputs
    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;

    char *result = NULL;
    if (a >= 0.0 && a < 1.0) {
        // rgba format with alpha (e.g., "rgba(255,0,128,0.5)")
        // Max length: "rgba(255,255,255,1.000000)\0" ~ 30 chars
        result = (char *)malloc(32);
        if (!result) return NULL;
        snprintf(result, 32, "rgba(%d,%d,%d,%.6g)", r, g, b, a);
    } else {
        // rgb format without alpha (e.g., "rgb(255,0,128)")
        // Max length: "rgb(255,255,255)\0" ~ 18 chars
        result = (char *)malloc(20);
        if (!result) return NULL;
        snprintf(result, 20, "rgb(%d,%d,%d)", r, g, b);
    }
    return result;
}
