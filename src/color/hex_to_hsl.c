#include "color/hex_to_hsl.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

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

static int hex_to_rgb(const char* hex, int* r, int* g, int* b) {
    if (!hex || hex[0] != '#' || strlen(hex) != 7) return 0;

    int rr = parse_hex_component(hex + 1);
    int gg = parse_hex_component(hex + 3);
    int bb = parse_hex_component(hex + 5);

    if (rr == -1 || gg == -1 || bb == -1) return 0;

    *r = rr;
    *g = gg;
    *b = bb;
    return 1;
}

static void rgb_to_hsl(int r, int g, int b, HSL* out_hsl) {
    // Normalize r,g,b to [0,1]
    double rf = r / 255.0;
    double gf = g / 255.0;
    double bf = b / 255.0;

    double max = rf > gf ? (rf > bf ? rf : bf) : (gf > bf ? gf : bf);
    double min = rf < gf ? (rf < bf ? rf : bf) : (gf < bf ? gf : bf);
    double delta = max - min;

    double h = 0.0, s = 0.0, l = (max + min) / 2.0;

    if (delta == 0) {
        h = 0.0;
        s = 0.0;
    } else {
        s = (l < 0.5) ? (delta / (max + min)) : (delta / (2.0 - max - min));

        if (max == rf) {
            h = (gf - bf) / delta + (gf < bf ? 6.0 : 0.0);
        } else if (max == gf) {
            h = (bf - rf) / delta + 2.0;
        } else {
            h = (rf - gf) / delta + 4.0;
        }
        h *= 60.0;
        if (h < 0.0) h += 360.0;
    }

    out_hsl->h = h;
    out_hsl->s = s * 100.0;
    out_hsl->l = l * 100.0;
}

EVERYUTIL_API int hex_to_hsl(const char* hex, HSL* out_hsl) {
    if (!out_hsl) return 0;

    int r, g, b;
    if (!hex_to_rgb(hex, &r, &g, &b)) return 0;

    rgb_to_hsl(r, g, b, out_hsl);
    return 1;
}