#include "color/rgb_to_hsl.h"
#include <math.h>

EVERYUTIL_API ColorHSL rgb_to_hsl(int r, int g, int b) {
    double rd = r / 255.0;
    double gd = g / 255.0;
    double bd = b / 255.0;

    double max = fmax(fmax(rd, gd), bd);
    double min = fmin(fmin(rd, gd), bd);
    double h = 0.0, s = 0.0, l = (max + min) / 2.0;

    if (max != min) {
        double d = max - min;
        s = l > 0.5 ? d / (2.0 - max - min) : d / (max + min);

        if (max == rd) {
            h = (gd - bd) / d + (gd < bd ? 6.0 : 0.0);
        } else if (max == gd) {
            h = (bd - rd) / d + 2.0;
        } else if (max == bd) {
            h = (rd - gd) / d + 4.0;
        }
        h *= 60.0;
    }

    ColorHSL hsl = { h, s * 100.0, l * 100.0 };
    return hsl;
}