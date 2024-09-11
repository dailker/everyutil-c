#include "color/invert_color.h"
#include <stdlib.h>
EVERYUTIL_API char *invert_color(const char *hex_color) {
    unsigned char r, g, b;
    if (!parse_hex_color(hex_color, &r, &g, &b)) return NULL;
    return rgb_to_hex(255 - r, 255 - g, 255 - b);
}