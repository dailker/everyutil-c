#include "color/simulate_lighting_on_color.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>
#include <math.h>

EVERYUTIL_API char* simulate_lighting_on_color(const char* color, double brightness_factor) {
    if (!color || brightness_factor < 0) return NULL;

    color_rgba_t c;
    if (!parse_color_string(color, &c)) {
        return NULL;
    }

    double r = c.r * brightness_factor;
    double g = c.g * brightness_factor;
    double b = c.b * brightness_factor;

    int rr = (int)(r < 0 ? 0 : r > 255 ? 255 : r);
    int gg = (int)(g < 0 ? 0 : g > 255 ? 255 : g);
    int bb = (int)(b < 0 ? 0 : b > 255 ? 255 : b);

    return rgb_to_hex(rr, gg, bb);
}