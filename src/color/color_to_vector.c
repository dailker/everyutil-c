#include "color/color_to_vector.h"
#include <stdlib.h>

double *color_to_vector(const char *color_str, const color_rgba_t *color_obj) {
    color_rgba_t c;

    if (color_obj) {
        c = *color_obj;
    } else if (color_str) {
        if (!parse_color_string(color_str, &c)) {
            // On failure return default black opaque
            double *def = (double *)malloc(4 * sizeof(double));
            if (!def) return NULL;
            def[0] = 0.0;
            def[1] = 0.0;
            def[2] = 0.0;
            def[3] = 1.0;
            return def;
        }
    } else {
        // No input given, return default
        double *def = (double *)malloc(4 * sizeof(double));
        if (!def) return NULL;
        def[0] = 0.0;
        def[1] = 0.0;
        def[2] = 0.0;
        def[3] = 1.0;
        return def;
    }

    double *vec = (double *)malloc(4 * sizeof(double));
    if (!vec) return NULL;

    vec[0] = (double)c.r;
    vec[1] = (double)c.g;
    vec[2] = (double)c.b;
    vec[3] = (c.a >= 0.0 && c.a <= 1.0) ? c.a : 1.0;

    return vec;
}
