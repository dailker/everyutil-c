#include "color/generate_palette.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

static int parse_hex_color(const char* hex, double* r, double* g, double* b) {
    if (!hex || strlen(hex) != 7 || hex[0] != '#') return 0;
    unsigned int ri, gi, bi;
    if (sscanf(hex + 1, "%2x%2x%2x", &ri, &gi, &bi) != 3) return 0;
    *r = ri / 255.0;
    *g = gi / 255.0;
    *b = bi / 255.0;
    return 1;
}

static void rgb_to_hsl(double r, double g, double b, double* h, double* s, double* l) {
    double max = fmax(r, fmax(g, b));
    double min = fmin(r, fmin(g, b));
    *l = (max + min) / 2.0;

    if (max == min) {
        *h = *s = 0.0;
    } else {
        double d = max - min;
        *s = (*l > 0.5) ? (d / (2.0 - max - min)) : (d / (max + min));
        if (max == r)
            *h = fmod((g - b) / d + (g < b ? 6 : 0), 6.0);
        else if (max == g)
            *h = (b - r) / d + 2.0;
        else
            *h = (r - g) / d + 4.0;
        *h *= 60.0;
    }
}

static double hue_to_rgb(double p, double q, double t) {
    if (t < 0.0) t += 1.0;
    if (t > 1.0) t -= 1.0;
    if (t < 1.0 / 6.0) return p + (q - p) * 6.0 * t;
    if (t < 1.0 / 2.0) return q;
    if (t < 2.0 / 3.0) return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
    return p;
}

static void hsl_to_rgb(double h, double s, double l, double* r, double* g, double* b) {
    h = fmod(h, 360.0);
    if (h < 0) h += 360.0;
    h /= 360.0;

    if (s == 0.0) {
        *r = *g = *b = l;
    } else {
        double q = l < 0.5 ? (l * (1.0 + s)) : (l + s - l * s);
        double p = 2.0 * l - q;
        *r = hue_to_rgb(p, q, h + 1.0 / 3.0);
        *g = hue_to_rgb(p, q, h);
        *b = hue_to_rgb(p, q, h - 1.0 / 3.0);
    }
}

static char* rgb_to_hex(double r, double g, double b) {
    char* hex = (char*)malloc(8);
    if (!hex) return NULL;
    int ri = (int)round(r * 255.0);
    int gi = (int)round(g * 255.0);
    int bi = (int)round(b * 255.0);
    snprintf(hex, 8, "#%02X%02X%02X", ri, gi, bi);
    return hex;
}

static char** alloc_palette(size_t n) {
    char** palette = (char**)malloc(sizeof(char*) * (n + 1));
    if (!palette) return NULL;
    for (size_t i = 0; i <= n; ++i) palette[i] = NULL;
    return palette;
}

EVERYUTIL_API char** generate_palette(const char* base_hex, const char* scheme_type) {
    double r, g, b, h, s, l;
    if (!parse_hex_color(base_hex, &r, &g, &b)) return NULL;
    rgb_to_hsl(r, g, b, &h, &s, &l);

    size_t count = 1;
    double hs[3] = { h };
    if (strcmp(scheme_type, "complementary") == 0) {
        hs[1] = fmod(h + 180.0, 360.0);
        count = 2;
    } else if (strcmp(scheme_type, "triadic") == 0) {
        hs[1] = fmod(h + 120.0, 360.0);
        hs[2] = fmod(h + 240.0, 360.0);
        count = 3;
    } else if (strcmp(scheme_type, "analogous") == 0) {
        hs[0] = fmod(h - 30.0 + 360.0, 360.0);
        hs[1] = h;
        hs[2] = fmod(h + 30.0, 360.0);
        count = 3;
    }

    char** result = alloc_palette(count);
    if (!result) return NULL;

    for (size_t i = 0; i < count; ++i) {
        double cr, cg, cb;
        hsl_to_rgb(hs[i], s, l, &cr, &cg, &cb);
        result[i] = rgb_to_hex(cr, cg, cb);
        if (!result[i]) {
            for (size_t j = 0; j < i; ++j) free(result[j]);
            free(result);
            return NULL;
        }
    }

    result[count] = NULL;
    return result;
}