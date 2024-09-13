#include "color/pixelate_color.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>
#include <math.h>

EVERYUTIL_API char* pixelate_color(const char* color, int pixel_size) {
    if (!color || pixel_size <= 0) return NULL;

    color_rgba_t c;
    if (!parse_color_string(color, &c)) {
        return NULL;
    }

    int r = ((int)floor(c.r / pixel_size)) * pixel_size;
    int g = ((int)floor(c.g / pixel_size)) * pixel_size;
    int b = ((int)floor(c.b / pixel_size)) * pixel_size;

    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;

    return rgb_to_hex(r, g, b);
}