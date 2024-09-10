#include "color/generate_accessible_palette.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double r, g, b;
} RGB;

typedef struct {
    double h, s, l;
} HSL;

// --- Utilities ---

static int parse_hex_color(const char* hex, RGB* out) {
    if (!hex || hex[0] != '#' || strlen(hex) != 7) return 0;
    unsigned int r, g, b;
    if (sscanf(hex + 1, "%2x%2x%2x", &r, &g, &b) != 3) return 0;
    out->r = r / 255.0;
    out->g = g / 255.0;
    out->b = b / 255.0;
    return 1;
}

static void rgb_to_hsl(const RGB* rgb, HSL* hsl) {
    double r = rgb->r, g = rgb->g, b = rgb->b;
    double max = fmax(r, fmax(g, b));
    double min = fmin(r, fmin(g, b));
    double h = 0, s, l = (max + min) / 2;
    if (max == min) {
        h = s = 0;
    } else {
        double d = max - min;
        s = l > 0.5 ? d / (2 - max - min) : d / (max + min);
        if (max == r) h = (g - b) / d + (g < b ? 6 : 0);
        else if (max == g) h = (b - r) / d + 2;
        else h = (r - g) / d + 4;
        h /= 6;
    }
    hsl->h = h;
    hsl->s = s;
    hsl->l = l;
}

static double hue_to_rgb(double p, double q, double t) {
    if (t < 0) t += 1;
    if (t > 1) t -= 1;
    if (t < 1.0/6) return p + (q - p) * 6 * t;
    if (t < 1.0/2) return q;
    if (t < 2.0/3) return p + (q - p) * (2.0/3 - t) * 6;
    return p;
}

static void hsl_to_rgb(const HSL* hsl, RGB* rgb) {
    double h = hsl->h, s = hsl->s, l = hsl->l;
    if (s == 0) {
        rgb->r = rgb->g = rgb->b = l;
    } else {
        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2 * l - q;
        rgb->r = hue_to_rgb(p, q, h + 1.0/3);
        rgb->g = hue_to_rgb(p, q, h);
        rgb->b = hue_to_rgb(p, q, h - 1.0/3);
    }
}

static char* rgb_to_hex(const RGB* rgb) {
    char* result = (char*)malloc(8);
    if (!result) return NULL;
    int r = (int)(rgb->r * 255 + 0.5);
    int g = (int)(rgb->g * 255 + 0.5);
    int b = (int)(rgb->b * 255 + 0.5);
    snprintf(result, 8, "#%02X%02X%02X", r, g, b);
    return result;
}

// --- Luminance and Contrast ---

static double luminance(const RGB* rgb) {
    double c[3] = { rgb->r, rgb->g, rgb->b };
    for (int i = 0; i < 3; ++i) {
        c[i] = (c[i] <= 0.03928) ? c[i] / 12.92 : pow((c[i] + 0.055) / 1.055, 2.4);
    }
    return 0.2126 * c[0] + 0.7152 * c[1] + 0.0722 * c[2];
}

static double contrast_ratio(const RGB* a, const RGB* b) {
    double l1 = luminance(a);
    double l2 = luminance(b);
    if (l1 > l2) return (l1 + 0.05) / (l2 + 0.05);
    return (l2 + 0.05) / (l1 + 0.05);
}

// --- Main Function ---

EVERYUTIL_API char** generate_accessible_palette(const char* base_color) {
    if (!base_color) return NULL;

    RGB base_rgb;
    if (!parse_hex_color(base_color, &base_rgb)) return NULL;

    HSL base_hsl;
    rgb_to_hsl(&base_rgb, &base_hsl);

    size_t count = 5;
    double hue_offsets[] = {-0.0833, -0.0417, 0.0, 0.0417, 0.0833}; // ±30°, ±15°, 0

    char** result = (char**)malloc(sizeof(char*) * (count + 1));
    if (!result) return NULL;

    size_t j = 0;
    for (size_t i = 0; i < count; ++i) {
        HSL hsl = base_hsl;
        hsl.h += hue_offsets[i];
        if (hsl.h < 0) hsl.h += 1;
        if (hsl.h > 1) hsl.h -= 1;

        RGB candidate_rgb;
        hsl_to_rgb(&hsl, &candidate_rgb);

        if (contrast_ratio(&base_rgb, &candidate_rgb) >= 4.5) {
            char* hex = rgb_to_hex(&candidate_rgb);
            if (!hex) {
                for (size_t k = 0; k < j; ++k) free(result[k]);
                free(result);
                return NULL;
            }
            result[j++] = hex;
        }
    }

    result[j] = NULL;
    return result;
}