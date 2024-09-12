#include "color/rgb_to_lab.h"
#include "color/rgb_to_xyz.h"
#include <math.h>

static double pivot_xyz(double v) {
    return v > 0.008856 ? cbrt(v) : (7.787 * v) + (16.0 / 116.0);
}

EVERYUTIL_API ColorLab rgb_to_lab(int r, int g, int b) {
    // Use ColorXYZ from header:
    ColorXYZ xyz = rgb_to_xyz(r, g, b);

    double x = xyz.x / 95.047;
    double y = xyz.y / 100.0;
    double z = xyz.z / 108.883;

    x = pivot_xyz(x);
    y = pivot_xyz(y);
    z = pivot_xyz(z);

    ColorLab lab;
    lab.l = 116.0 * y - 16.0;
    lab.a = 500.0 * (x - y);
    lab.b = 200.0 * (y - z);

    return lab;
}
