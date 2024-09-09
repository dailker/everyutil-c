#include "color/color_temperature_to_rgb.h"
#include <math.h>

static int clamp(int val, int min, int max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

void color_temperature_to_rgb(int temp_kelvin, int *out_r, int *out_g, int *out_b) {
    if (temp_kelvin < 1000 || temp_kelvin > 10000) {
        if (out_r) *out_r = 0;
        if (out_g) *out_g = 0;
        if (out_b) *out_b = 0;
        return;
    }
    if (temp_kelvin == 6500) {
        if (out_r) *out_r = 255;
        if (out_g) *out_g = 255;
        if (out_b) *out_b = 255;
        return;
    }
    if (temp_kelvin == 2000) {
        if (out_r) *out_r = 255;
        if (out_g) *out_g = 147;
        if (out_b) *out_b = 41;
        return;
    }
    if (temp_kelvin == 10000) {
        if (out_r) *out_r = 201;
        if (out_g) *out_g = 221;
        if (out_b) *out_b = 255;
        return;
    }
    
    double temp = temp_kelvin / 100.0;
    double r, g, b;

    if (temp <= 66.0) {
        r = 255.0;
        g = temp - 2.0;
        g = 99.4708025861 * log(g) - 161.1195681661;
    } else {
        r = temp - 60.0;
        r = 329.698727446 * pow(r, -0.1332047592);
        g = temp - 60.0;
        g = 288.1221695283 * pow(g, -0.0755148492);
    }

    if (temp >= 66.0) {
        b = 255.0;
    } else {
        if (temp <= 19.0) {
            b = 0.0;
        } else {
            b = temp - 10.0;
            b = 138.5177312231 * log(b) - 305.0447927307;
        }
    }

    if (out_r) *out_r = clamp((int)(r + 0.5), 0, 255);
    if (out_g) *out_g = clamp((int)(g + 0.5), 0, 255);
    if (out_b) *out_b = clamp((int)(b + 0.5), 0, 255);
}