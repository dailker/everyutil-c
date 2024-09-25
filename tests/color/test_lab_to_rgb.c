#include <stdio.h>
#include <math.h>
#include "color/lab_to_rgb.h"

int main(void) {
    rgb_t rgb;
    
    // Test white point (L=100, a=0, b=0)
    rgb = labToRgb(100.0, 0.0, 0.0);
    if (rgb.r > 250 && rgb.g > 250 && rgb.b > 250) {
        printf("white point: PASSED\n");
    } else {
        printf("white point: FAILED (r:%d g:%d b:%d)\n", rgb.r, rgb.g, rgb.b);
    }
    
    // Test black point (L=0, a=0, b=0)
    rgb = labToRgb(0.0, 0.0, 0.0);
    if (rgb.r < 5 && rgb.g < 5 && rgb.b < 5) {
        printf("black point: PASSED\n");
    } else {
        printf("black point: FAILED (r:%d g:%d b:%d)\n", rgb.r, rgb.g, rgb.b);
    }
    
    // Test mid-gray (L=50, a=0, b=0)
    rgb = labToRgb(50.0, 0.0, 0.0);
    if (rgb.r > 100 && rgb.r < 150 && rgb.g > 100 && rgb.g < 150 && rgb.b > 100 && rgb.b < 150) {
        printf("mid-gray: PASSED\n");
    } else {
        printf("mid-gray: FAILED (r:%d g:%d b:%d)\n", rgb.r, rgb.g, rgb.b);
    }
    
    // Test red-ish color (L=50, a=50, b=0)
    rgb = labToRgb(50.0, 50.0, 0.0);
    if (rgb.r > rgb.g && rgb.r > rgb.b) {
        printf("red-ish color: PASSED\n");
    } else {
        printf("red-ish color: FAILED (r:%d g:%d b:%d)\n", rgb.r, rgb.g, rgb.b);
    }
    
    return 0;
}