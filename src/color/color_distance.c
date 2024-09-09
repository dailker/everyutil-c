#include "color/color_distance.h"
#include <math.h>

EVERYUTIL_API double color_distance(const uint8_t color1[3], const uint8_t color2[3]) {
    if (!color1 || !color2) return -1.0;

    double sum = 0.0;
    for (int i = 0; i < 3; i++) {
        double diff = (double)color1[i] - (double)color2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}