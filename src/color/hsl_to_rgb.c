#include "color/hsl_to_rgb.h"
#include <math.h>
static double mod12(double n) {
    double r = fmod(n, 12.0);
    return (r < 0) ? r + 12.0 : r;
}
static double f(double n, double h, double a, double l) {
    double k = mod12(n + h / 30.0);
    double val = l - a * fmax(-1.0, fmin(fmin(k - 3.0, 9.0 - k), 1.0));
    return val;
}
EVERYUTIL_API int hsl_to_rgb(double h, double s, double l, RGB* out_rgb) {
    if (!out_rgb) return 0;
    if (h < 0) h = 0;
    if (h > 360) h = 360;
    if (s < 0) s = 0;
    if (s > 100) s = 100;
    if (l < 0) l = 0;
    if (l > 100) l = 100;
    s /= 100.0;
    l /= 100.0;
    double a = s * (l < 0.5 ? l : (1 - l));
    double rf = f(0, h, a, l);
    double gf = f(8, h, a, l);
    double bf = f(4, h, a, l);
    out_rgb->r = (int)round(rf * 255.0);
    out_rgb->g = (int)round(gf * 255.0);
    out_rgb->b = (int)round(bf * 255.0);
    if (out_rgb->r < 0) out_rgb->r = 0; else if (out_rgb->r > 255) out_rgb->r = 255;
    if (out_rgb->g < 0) out_rgb->g = 0; else if (out_rgb->g > 255) out_rgb->g = 255;
    if (out_rgb->b < 0) out_rgb->b = 0; else if (out_rgb->b > 255) out_rgb->b = 255;
    return 1;
}