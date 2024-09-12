#include "color/lighten.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Helper: parse hex digit
static int hex_digit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    return -1;
}

// Parse #RRGGBB format
static int parse_hex_color(const char* color, int* r, int* g, int* b) {
    if (!color || color[0] != '#') return 0;
    size_t len = strlen(color);
    if (len != 7) return 0; // Only support #RRGGBB

    int hr = hex_digit(color[1]);
    int hl = hex_digit(color[2]);
    int gr = hex_digit(color[3]);
    int gl = hex_digit(color[4]);
    int br = hex_digit(color[5]);
    int bl = hex_digit(color[6]);

    if (hr < 0 || hl < 0 || gr < 0 || gl < 0 || br < 0 || bl < 0) return 0;

    *r = hr * 16 + hl;
    *g = gr * 16 + gl;
    *b = br * 16 + bl;
    return 1;
}

// Convert r,g,b to hex string "#rrggbb", returns malloc'ed string
static char* rgb_to_hex(int r, int g, int b) {
    char* out = (char*)malloc(8);
    if (!out) return NULL;
    snprintf(out, 8, "#%02x%02x%02x", r, g, b);
    return out;
}

EVERYUTIL_API char* lighten(const char* color, double amount) {
    if (!color) return NULL;
    if (amount < 0.0) amount = 0.0;
    if (amount > 1.0) amount = 1.0;

    int r, g, b;
    if (!parse_hex_color(color, &r, &g, &b)) {
        // Invalid color, return copy of original
        size_t len = strlen(color);
        char* copy = (char*)malloc(len + 1);
        if (!copy) return NULL;
        memcpy(copy, color, len + 1);
        return copy;
    }

    int nr = r + (int)((255 - r) * amount + 0.5);
    int ng = g + (int)((255 - g) * amount + 0.5);
    int nb = b + (int)((255 - b) * amount + 0.5);

    if (nr > 255) nr = 255;
    if (ng > 255) ng = 255;
    if (nb > 255) nb = 255;

    return rgb_to_hex(nr, ng, nb);
}