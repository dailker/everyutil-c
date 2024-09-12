#include "color/lab_to_rgb.h"
#include <math.h>
#include <stdint.h>



static double inverse_pivot_xyz(double n) {
    double n3 = n * n * n;
    return (n3 > 0.008856) ? n3 : (n - 16.0/116.0) / 7.787;
}

/**
 * Converts XYZ color to RGB.
 * Input X, Y, Z in standard D65 illuminant reference scale.
 * Output r,g,b in 0-255.
 */
static rgb_t xyzToRgb(double x, double y, double z) {
    // Normalize for D65 white point
    x /= 100.0;
    y /= 100.0;
    z /= 100.0;

    // Convert XYZ to linear RGB (sRGB)
    double r = x *  3.2406 + y * (-1.5372) + z * (-0.4986);
    double g = x * (-0.9689) + y *  1.8758 + z *  0.0415;
    double b = x *  0.0557 + y * (-0.2040) + z *  1.0570;

    // Apply gamma correction
    #define GAMMA_CORRECT(c) ((c) <= 0.0031308 ? 12.92*(c) : 1.055*pow((c), 1.0/2.4) - 0.055)

    r = GAMMA_CORRECT(r);
    g = GAMMA_CORRECT(g);
    b = GAMMA_CORRECT(b);

    // Clamp to [0,1]
    if (r < 0.0) r = 0.0; else if (r > 1.0) r = 1.0;
    if (g < 0.0) g = 0.0; else if (g > 1.0) g = 1.0;
    if (b < 0.0) b = 0.0; else if (b > 1.0) b = 1.0;

    rgb_t result = {
        (uint8_t)(r * 255.0 + 0.5),
        (uint8_t)(g * 255.0 + 0.5),
        (uint8_t)(b * 255.0 + 0.5)
    };
    return result;
}

EVERYUTIL_API rgb_t labToRgb(double l, double a, double b) {
    // Convert LAB to XYZ
    double y = (l + 16.0) / 116.0;
    double x = a / 500.0 + y;
    double z = y - b / 200.0;

    x = inverse_pivot_xyz(x) * 95.047;
    y = inverse_pivot_xyz(y) * 100.000;
    z = inverse_pivot_xyz(z) * 108.883;

    return xyzToRgb(x, y, z);
}