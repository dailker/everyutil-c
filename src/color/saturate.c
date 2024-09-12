#include "color/saturate.h"
#include "color/rgb_to_hsl.h"
#include "color/hsl_to_rgb.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>

EVERYUTIL_API char* saturate(const char* color, double factor) {
    if (!color || factor < 0) return NULL;

    color_rgba_t c;
    if (!parse_color_string(color, &c)) {
        return NULL;
    }

    ColorHSL hsl = rgb_to_hsl(c.r, c.g, c.b);
    hsl.s *= factor;
    if (hsl.s > 100.0) hsl.s = 100.0;
    if (hsl.s < 0.0) hsl.s = 0.0;

    RGB rgb;
    if (!hsl_to_rgb(hsl.h, hsl.s, hsl.l, &rgb)) {
        return NULL;
    }

    return rgb_to_hex(rgb.r, rgb.g, rgb.b);
}