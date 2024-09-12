#include "color/is_color_dark.h"
EVERYUTIL_API bool is_color_dark(const char *hex_color) {
    unsigned char r, g, b;
    if (!parse_hex_color(hex_color, &r, &g, &b)) return false;
    int brightness = get_brightness(r, g, b);
    return brightness < 128;
}