#include "color/parse_color_string.h"
#include "color/parse_hex_color.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
EVERYUTIL_API int parse_color_string(const char *str, color_rgba_t *out_color) {
    if (!str || !out_color) return 0;
    if (str[0] == '#') {
        unsigned char r, g, b;
        if (!parse_hex_color(str, &r, &g, &b)) return 0;
        out_color->r = r;
        out_color->g = g;
        out_color->b = b;
        out_color->a = 1.0;
        return 1;
    }
    if (strncmp(str, "rgb(", 4) == 0 || strncmp(str, "rgba(", 5) == 0) {
        int r, g, b;
        float a = 1.0;
        if (strncmp(str, "rgba(", 5) == 0) {
            if (sscanf(str, "rgba(%d,%d,%d,%f)", &r, &g, &b, &a) != 4) return 0;
        } else {
            if (sscanf(str, "rgb(%d,%d,%d)", &r, &g, &b) != 3) return 0;
        }
        if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || a < 0.0 || a > 1.0) return 0;
        out_color->r = r;
        out_color->g = g;
        out_color->b = b;
        out_color->a = a;
        return 1;
    }
    return 0;
}