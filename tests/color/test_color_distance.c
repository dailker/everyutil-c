#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "color/color_distance.h"

void run_test(const char* name, uint8_t color1[3], uint8_t color2[3], double expected, double tolerance) {
    double result = color_distance(color1, color2);
    int passed = (fabs(result - expected) <= tolerance);
    printf("%s: %s\n", name, passed ? "PASSED" : "FAILED");
}

void test_color_distance_same() {
    uint8_t color1[3] = {100, 100, 100};
    uint8_t color2[3] = {100, 100, 100};
    run_test("test_color_distance_same", color1, color2, 0.0, 0.0001);
}

void test_color_distance_different() {
    uint8_t color1[3] = {255, 0, 0};   // Red
    uint8_t color2[3] = {0, 255, 0};   // Green
    // Expected Euclidean distance: sqrt((255-0)^2 + (0-255)^2 + (0-0)^2) = sqrt(2 * 255^2) ≈ 360.624
    run_test("test_color_distance_different", color1, color2, 360.624, 0.001);
}

void test_color_distance_max() {
    uint8_t color1[3] = {255, 255, 255}; // White
    uint8_t color2[3] = {0, 0, 0};       // Black
    // Expected Euclidean distance: sqrt(255^2 + 255^2 + 255^2) ≈ 441.673
    run_test("test_color_distance_max", color1, color2, 441.673, 0.001);
}

int main(void) {
    test_color_distance_same();
    test_color_distance_different();
    test_color_distance_max();
    return 0;
}