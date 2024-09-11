#include "color/hsl_to_hex.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void hsl_to_rgb(double h, double s, double l, int* r, int* g, int* b) {
    s /= 100.0;
    l /= 100.0;

    double c = (1.0 - fabs(2.0 * l - 1.0)) * s;
    double hh = h / 60.0;
    double x = c * (1.0 - fabs(fmod(hh, 2.0) - 1.0));
    double r1, g1, b1;

    if (hh >= 0 && hh < 1) {
        r1 = c; g1 = x; b1 = 0;
    } else if (hh < 2) {
        r1 = x; g1 = c; b1 = 0;
    } else if (hh < 3) {
        r1 = 0; g1 = c; b1 = x;
    } else if (hh < 4) {
        r1 = 0; g1 = x; b1 = c;
    } else if (hh < 5) {
        r1 = x; g1 = 0; b1 = c;
    } else {
        r1 = c; g1 = 0; b1 = x;
    }

    double m = l - c / 2.0;

    *r = (int)round((r1 + m) * 255.0);
    *g = (int)round((g1 + m) * 255.0);
    *b = (int)round((b1 + m) * 255.0);

    if (*r < 0) *r = 0;
    if (*r > 255) *r = 255;
    if (*g < 0) *g = 0;
    if (*g > 255) *g = 255;
    if (*b < 0) *b = 0;
    if (*b > 255) *b = 255;
}

EVERYUTIL_API char* hsl_to_hex(double h, double s, double l) {
    int r, g, b;
    hsl_to_rgb(h, s, l, &r, &g, &b);

    char* hex = (char*)malloc(8); // 7 chars + '\0'
    if (!hex) return NULL;

    snprintf(hex, 8, "#%02x%02x%02x", r, g, b);
    return hex;
}
