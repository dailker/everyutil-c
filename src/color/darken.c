#include "color/darken.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Reuse parse_hex_color and rgb_to_hex helpers from blend_modes.c or your utils:

typedef struct {
    int r, g, b;
} RGB;

static int hex_digit_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    else if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    else return -1;
}

static int parse_hex_color(const char *str, RGB *out) {
    if (!str || str[0] != '#') return 0;
    size_t len = strlen(str);
    if (len == 7) {
        int r1 = hex_digit_to_int(str[1]);
        int r2 = hex_digit_to_int(str[2]);
        int g1 = hex_digit_to_int(str[3]);
        int g2 = hex_digit_to_int(str[4]);
        int b1 = hex_digit_to_int(str[5]);
        int b2 = hex_digit_to_int(str[6]);
        if (r1 < 0 || r2 < 0 || g1 < 0 || g2 < 0 || b1 < 0 || b2 < 0) return 0;
        out->r = r1 * 16 + r2;
        out->g = g1 * 16 + g2;
        out->b = b1 * 16 + b2;
        return 1;
    } else if (len == 4) {
        int r = hex_digit_to_int(str[1]);
        int g = hex_digit_to_int(str[2]);
        int b = hex_digit_to_int(str[3]);
        if (r < 0 || g < 0 || b < 0) return 0;
        out->r = r * 17;
        out->g = g * 17;
        out->b = b * 17;
        return 1;
    }
    return 0;
}

static char *rgb_to_hex(int r, int g, int b) {
    char *result = (char *)malloc(8);
    if (!result) return NULL;
    if (r < 0) r = 0; else if (r > 255) r = 255;
    if (g < 0) g = 0; else if (g > 255) g = 255;
    if (b < 0) b = 0; else if (b > 255) b = 255;
    snprintf(result, 8, "#%02x%02x%02x", r, g, b);
    return result;
}

EVERYUTIL_API char *darken(const char *color, double amount) {
    if (!color) return NULL;
    if (amount < 0.0) amount = 0.0;
    if (amount > 1.0) amount = 1.0;

    RGB c;
    if (!parse_hex_color(color, &c)) {
        // Return a copy of original on failure
        size_t len = strlen(color);
        char *copy = malloc(len + 1);
        if (!copy) return NULL;
        memcpy(copy, color, len + 1);
        return copy;
    }

    int r = (int)(c.r * (1.0 - amount) + 0.5);
    int g = (int)(c.g * (1.0 - amount) + 0.5);
    int b = (int)(c.b * (1.0 - amount) + 0.5);

    return rgb_to_hex(r, g, b);
}