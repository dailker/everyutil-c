#include "color/vector_to_color.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>
#include <math.h>

EVERYUTIL_API char* vector_to_color(const Vector3 *vector) {
    if (!vector) return NULL;

    double x = fmax(0.0, fmin(1.0, vector->x));
    double y = fmax(0.0, fmin(1.0, vector->y));
    double z = fmax(0.0, fmin(1.0, vector->z));

    int r = (int)(x * 255.0);
    int g = (int)(y * 255.0);
    int b = (int)(z * 255.0);

    return rgb_to_hex(r, g, b);
}