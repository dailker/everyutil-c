#include "color/contrast_ratio.h"

double contrast_ratio(const char *color1, const char *color2) {
    if (!color1 || !color2) return -1.0;

    double l1 = get_luminance(color1);
    double l2 = get_luminance(color2);

    if (l1 < 0.0 || l2 < 0.0) return -1.0;

    l1 += 0.05;
    l2 += 0.05;

    return (l1 > l2) ? (l1 / l2) : (l2 / l1);
}
