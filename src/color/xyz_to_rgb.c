#include "color/xyz_to_rgb.h"
#include <math.h>

static double pivot_xyz(double n) {
    return n > 0.0031308 ? 1.055 * pow(n, 1.0 / 2.4) - 0.055 : 12.92 * n;
}

EVERYUTIL_API RGB xyz_to_rgb(ColorXYZ xyz) {
    double x = xyz.x / 100.0;
    double y = xyz.y / 100.0;
    double z = xyz.z / 100.0;

    double r = x * 3.2406 + y * -1.5372 + z * -0.4986;
    double g = x * -0.9689 + y * 1.8758 + z * 0.0415;
    double b = x * 0.0557 + y * -0.2040 + z * 1.0570;

    r = pivot_xyz(r);
    g = pivot_xyz(g);
    b = pivot_xyz(b);

    int rr = (int)(r * 255.0);
    int gg = (int)(g * 255.0);
    int bb = (int)(b * 255.0);

    if (rr < 0) rr = 0; else if (rr > 255) rr = 255;
    if (gg < 0) gg = 0; else if (gg > 255) gg = 255;
    if (bb < 0) bb = 0; else if (bb > 255) bb = 255;

    RGB rgb = { rr, gg, bb };
    return rgb;
}