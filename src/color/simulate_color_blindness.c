#include "color/simulate_color_blindness.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>

EVERYUTIL_API char* simulate_color_blindness(const char* color, ColorBlindnessType type) {
    if (!color) return NULL;

    color_rgba_t c;
    if (!parse_color_string(color, &c)) {
        return NULL;
    }

    double r = c.r;
    double g = c.g;
    double b = c.b;

    switch (type) {
        case PROTANOPIA:
            r = 0.56667 * c.r + 0.43333 * c.g;
            g = 0.55833 * c.r + 0.44167 * c.g;
            b = 0.24167 * c.g + 0.75833 * c.b;
            break;
        case DEUTERANOPIA:
            r = 0.625 * c.r + 0.375 * c.g;
            g = 0.7 * c.g + 0.3 * c.r;
            b = 0.3 * c.g + 0.7 * c.b;
            break;
        case TRITANOPIA:
            r = 0.95 * c.r + 0.05 * c.b;
            g = 0.433 * c.g + 0.567 * c.b;
            b = 0.475 * c.g + 0.525 * c.b;
            break;
        default:
            return NULL;
    }

    int rr = (int)(r < 0 ? 0 : r > 255 ? 255 : r);
    int gg = (int)(g < 0 ? 0 : g > 255 ? 255 : g);
    int bb = (int)(b < 0 ? 0 : b > 255 ? 255 : b);

    return rgb_to_hex(rr, gg, bb);
}