#include "color/generate_gradient_colors.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

static int parse_hex_color(const char* hex, unsigned char* r, unsigned char* g, unsigned char* b) {
    if (!hex || hex[0] != '#' || strlen(hex) != 7) return 0;
    unsigned int rv, gv, bv;
    if (sscanf(hex + 1, "%2x%2x%2x", &rv, &gv, &bv) != 3) return 0;
    *r = (unsigned char)rv;
    *g = (unsigned char)gv;
    *b = (unsigned char)bv;
    return 1;
}

static char* rgb_to_hex(unsigned char r, unsigned char g, unsigned char b) {
    char* out = (char*)malloc(8); // "#RRGGBB" + null
    if (!out) return NULL;
    snprintf(out, 8, "#%02X%02X%02X", r, g, b);
    return out;
}

EVERYUTIL_API char** generate_gradient_colors(const char* start_hex, const char* end_hex, size_t steps) {
    if (!start_hex || !end_hex || steps < 2) return NULL;

    unsigned char sr, sg, sb, er, eg, eb;
    if (!parse_hex_color(start_hex, &sr, &sg, &sb)) return NULL;
    if (!parse_hex_color(end_hex, &er, &eg, &eb)) return NULL;

    char** result = (char**)malloc(sizeof(char*) * steps);
    if (!result) return NULL;

    for (size_t i = 0; i < steps; ++i) {
        double t = (double)i / (double)(steps - 1);
        unsigned char r = (unsigned char)round(sr + (er - sr) * t);
        unsigned char g = (unsigned char)round(sg + (eg - sg) * t);
        unsigned char b = (unsigned char)round(sb + (eb - sb) * t);
        result[i] = rgb_to_hex(r, g, b);
        if (!result[i]) {
            for (size_t j = 0; j < i; ++j) free(result[j]);
            free(result);
            return NULL;
        }
    }

    return result;
}