#include "color/rgb_to_xyz.h"
#include <math.h>
static double pivot_rgb(double c) {
    if (c > 0.04045)
        return pow((c + 0.055) / 1.055, 2.4);
    else
        return c / 12.92;
}
EVERYUTIL_API ColorXYZ rgb_to_xyz(int r, int g, int b) {
    double rd = r / 255.0;
    double gd = g / 255.0;
    double bd = b / 255.0;
    rd = pivot_rgb(rd);
    gd = pivot_rgb(gd);
    bd = pivot_rgb(bd);
    rd *= 100.0;
    gd *= 100.0;
    bd *= 100.0;
    ColorXYZ xyz = {
        .x = rd * 0.4124 + gd * 0.3576 + bd * 0.1805,
        .y = rd * 0.2126 + gd * 0.7152 + bd * 0.0722,
        .z = rd * 0.0193 + gd * 0.1192 + bd * 0.9505
    };
    return xyz;
}