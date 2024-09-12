#include "color/get_luminance.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Color struct and parser reused from previous code (hex #RRGGBB and rgb(...))
typedef struct {
    int r, g, b;
} Color;

static int parse_hex_digit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    return -1;
}

static int parse_hex_component(const char* s) {
    int hi = parse_hex_digit(s[0]);
    int lo = parse_hex_digit(s[1]);
    if (hi == -1 || lo == -1) return -1;
    return (hi << 4) + lo;
}

static int parse_rgb_component(const char* s, int* value) {
    while (isspace((unsigned char)*s)) ++s;
    char* end;
    long val = strtol(s, &end, 10);
    if (end == s || val < 0 || val > 255) return 0;
    *value = (int)val;
    return 1;
}

static int parseColorString(const char* str, Color* out) {
    if (!str || !out) return 0;

    if (str[0] == '#' && strlen(str) == 7) {
        int r = parse_hex_component(str + 1);
        int g = parse_hex_component(str + 3);
        int b = parse_hex_component(str + 5);
        if (r < 0 || g < 0 || b < 0) return 0;
        out->r = r;
        out->g = g;
        out->b = b;
        return 1;
    }

    if (strncmp(str, "rgb(", 4) == 0) {
        const char* p = str + 4;
        int r, g, b;

        if (!parse_rgb_component(p, &r)) return 0;
        p = strchr(p, ','); if (!p) return 0; ++p;

        if (!parse_rgb_component(p, &g)) return 0;
        p = strchr(p, ','); if (!p) return 0; ++p;

        if (!parse_rgb_component(p, &b)) return 0;
        p = strchr(p, ')'); if (!p) return 0;

        out->r = r;
        out->g = g;
        out->b = b;
        return 1;
    }

    return 0;
}

EVERYUTIL_API double get_luminance(const char* color) {
    Color c;
    if (!parseColorString(color, &c)) {
        return 0.0;
    }

    double rgb[3];
    rgb[0] = c.r / 255.0;
    rgb[1] = c.g / 255.0;
    rgb[2] = c.b / 255.0;

    for (int i = 0; i < 3; ++i) {
        if (rgb[i] <= 0.03928) {
            rgb[i] = rgb[i] / 12.92;
        } else {
            rgb[i] = pow((rgb[i] + 0.055) / 1.055, 2.4);
        }
    }

    return 0.2126 * rgb[0] + 0.7152 * rgb[1] + 0.0722 * rgb[2];
}
