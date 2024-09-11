#include "color/generate_radial_gradient.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

static int parse_hex(const char* hex, unsigned char* r, unsigned char* g, unsigned char* b) {
    if (!hex || hex[0] != '#' || strlen(hex) != 7) return 0;
    unsigned int ri, gi, bi;
    if (sscanf(hex + 1, "%2x%2x%2x", &ri, &gi, &bi) != 3) return 0;
    *r = (unsigned char)ri;
    *g = (unsigned char)gi;
    *b = (unsigned char)bi;
    return 1;
}

static char* rgb_to_hex(unsigned char r, unsigned char g, unsigned char b) {
    char* hex = (char*)malloc(8); // "#RRGGBB" + null
    if (!hex) return NULL;
    snprintf(hex, 8, "#%02X%02X%02X", r, g, b);
    return hex;
}

EVERYUTIL_API char** generate_radial_gradient(const char* center_hex, const char* edge_hex, size_t steps) {
    if (!center_hex || !edge_hex || steps < 2) return NULL;

    unsigned char cr, cg, cb, er, eg, eb;
    if (!parse_hex(center_hex, &cr, &cg, &cb)) return NULL;
    if (!parse_hex(edge_hex, &er, &eg, &eb)) return NULL;

    char** result = (char**)malloc(sizeof(char*) * (steps + 1));
    if (!result) return NULL;

    for (size_t i = 0; i < steps; ++i) {
        double t = (double)i / (double)(steps - 1);
        unsigned char r = (unsigned char)round(cr + (er - cr) * t);
        unsigned char g = (unsigned char)round(cg + (eg - cg) * t);
        unsigned char b = (unsigned char)round(cb + (eb - cb) * t);

        result[i] = rgb_to_hex(r, g, b);
        if (!result[i]) {
            for (size_t j = 0; j < i; ++j) free(result[j]);
            free(result);
            return NULL;
        }
    }

    result[steps] = NULL;
    return result;
}