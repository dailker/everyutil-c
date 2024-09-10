#include "color/color_wheel_position.h"

double color_wheel_position(const char *color) {
    if (!color) return 0.0;

    color_rgba_t c;
    if (!parse_color_string(color, &c)) {
        return 0.0;
    }

    hsl_t hsl = rgb_to_hsl(c.r, c.g, c.b);
    return hsl.h;
}