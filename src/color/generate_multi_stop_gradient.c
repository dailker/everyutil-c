#include "color/generate_multi_stop_gradient.h"
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
    char* out = (char*)malloc(8); // "#RRGGBB" + '\0'
    if (!out) return NULL;
    snprintf(out, 8, "#%02X%02X%02X", r, g, b);
    return out;
}

EVERYUTIL_API char** generate_multi_stop_gradient(const char** hex_colors, size_t color_count, size_t stops) {
    if (!hex_colors || color_count < 2 || stops < 2) return NULL;

    size_t segments = color_count - 1;
    size_t steps_per_segment = stops / segments;
    size_t result_size = steps_per_segment * segments + 1;

    char** result = (char**)malloc(sizeof(char*) * (result_size + 1));
    if (!result) return NULL;

    size_t idx = 0;

    for (size_t i = 0; i < segments; ++i) {
        unsigned char sr, sg, sb, er, eg, eb;
        if (!parse_hex(hex_colors[i], &sr, &sg, &sb)) continue;
        if (!parse_hex(hex_colors[i + 1], &er, &eg, &eb)) continue;

        for (size_t j = 0; j < steps_per_segment; ++j) {
            double t = (double)j / (double)steps_per_segment;
            unsigned char r = (unsigned char)round(sr + (er - sr) * t);
            unsigned char g = (unsigned char)round(sg + (eg - sg) * t);
            unsigned char b = (unsigned char)round(sb + (eb - sb) * t);

            char* hex = rgb_to_hex(r, g, b);
            if (!hex) {
                for (size_t k = 0; k < idx; ++k) free(result[k]);
                free(result);
                return NULL;
            }
            result[idx++] = hex;
        }
    }

    // Append final color
    unsigned char fr, fg, fb;
    if (!parse_hex(hex_colors[color_count - 1], &fr, &fg, &fb)) {
        for (size_t k = 0; k < idx; ++k) free(result[k]);
        free(result);
        return NULL;
    }
    char* final_hex = rgb_to_hex(fr, fg, fb);
    if (!final_hex) {
        for (size_t k = 0; k < idx; ++k) free(result[k]);
        free(result);
        return NULL;
    }
    result[idx++] = final_hex;

    result[idx] = NULL;
    return result;
}