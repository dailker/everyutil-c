#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "color/average_color.h"

void test_average_color_basic() {
    uint8_t colors[][3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}}; // Red, Green, Blue
    size_t count = 3;
    size_t out_count;
    uint8_t* result = average_color(colors, count, &out_count);

    int passed = (result != NULL && out_count == 3 &&
                  result[0] == 85 &&  // (255 + 0 + 0) / 3 ≈ 85
                  result[1] == 85 &&  // (0 + 255 + 0) / 3 ≈ 85
                  result[2] == 85);   // (0 + 0 + 255) / 3 ≈ 85
    printf("test_average_color_basic: %s\n", passed ? "PASSED" : "FAILED");
    free(result);
}

void test_average_color_single() {
    uint8_t colors[][3] = {{100, 150, 200}};
    size_t count = 1;
    size_t out_count;
    uint8_t* result = average_color(colors, count, &out_count);

    int passed = (result != NULL && out_count == 1 &&
                  result[0] == 100 &&
                  result[1] == 150 &&
                  result[2] == 200);
    printf("test_average_color_single: %s\n", passed ? "PASSED" : "FAILED");
    free(result);
}

void test_average_color_empty() {
    uint8_t (*colors)[3] = NULL;
    size_t count = 0;
    size_t out_count;
    uint8_t* result = average_color(colors, count, &out_count);

    int passed = (result == NULL && out_count == 0);
    printf("test_average_color_empty: %s\n", passed ? "PASSED" : "FAILED");
}

int main(void) {
    test_average_color_basic();
    test_average_color_single();
    test_average_color_empty();
    return 0;
}