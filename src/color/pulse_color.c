#include "color/pulse_color.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>
#include <math.h>

EVERYUTIL_API char* pulse_color(const char* color, double intensity) {
    if (!color || intensity < 0) return NULL;

    color_rgba_t base;
    if (!parse_color_string(color, &base)) {
        return NULL;
    }

    double scale = 1.0 + intensity;
    if (scale < 0.0) scale = 0.0;
    if (scale > 2.0) scale = 2.0;

    int r = (int)(base.r * scale);
    int g = (int)(base.g * scale);
    int b = (int)(base.b * scale);

    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;

    return rgb_to_hex(r, g, b);
}