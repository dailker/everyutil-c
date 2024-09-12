#include "color/hex_to_rgb.h"
#include <string.h>
#include <ctype.h>

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

EVERYUTIL_API int hex_to_rgb(const char* hex, RGB* out_rgb) {
    if (!hex || !out_rgb) return 0;
    if (hex[0] != '#' || strlen(hex) != 7) return 0;

    int r = parse_hex_component(hex + 1);
    int g = parse_hex_component(hex + 3);
    int b = parse_hex_component(hex + 5);
    if (r == -1 || g == -1 || b == -1) return 0;

    out_rgb->r = r;
    out_rgb->g = g;
    out_rgb->b = b;
    return 1;
}
