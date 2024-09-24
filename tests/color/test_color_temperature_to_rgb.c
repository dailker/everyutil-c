#include <stdio.h>
#include <stdlib.h>

#include "color/color_temperature_to_rgb.h"

void run_test(const char* test_name, int temp_kelvin, int expected_r, int expected_g, int expected_b) {
    int r, g, b;
    color_temperature_to_rgb(temp_kelvin, &r, &g, &b);
    printf("%s: ", test_name);
    if (r == expected_r && g == expected_g && b == expected_b) {
        printf("PASSED\n");
    } else {
        printf("FAILED\n");
        printf("  Expected: (%d, %d, %d)\n", expected_r, expected_g, expected_b);
        printf("  Got:      (%d, %d, %d)\n", r, g, b);
    }
}

int main(void) {
    run_test("6500K (neutral)", 6500, 255, 255, 255); // Approximate
    run_test("2000K (warm)", 2000, 255, 147, 41);     // Approximate
    run_test("10000K (cool)", 10000, 201, 221, 255);  // Approximate
    run_test("invalid low temp", 0, 0, 0, 0);          // Implementation-dependent
    run_test("invalid high temp", 40000, 0, 0, 0);     // Implementation-dependent
    return 0;
}