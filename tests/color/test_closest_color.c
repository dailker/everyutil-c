#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "color/closest_color.h"

void test_closest_color_basic() {
    uint8_t target[3] = {100, 100, 100};
    uint8_t palette[][3] = {{0, 0, 0}, {255, 255, 255}, {100, 100, 100}}; // Black, White, Gray
    size_t palette_size = 3;
    const uint8_t* result = closest_color(target, palette, palette_size);

    int passed = (result != NULL && result == palette[2]); // Should match exact gray
    printf("test_closest_color_basic: %s\n", passed ? "PASSED" : "FAILED");
}

void test_closest_color_single() {
    uint8_t target[3] = {50, 50, 50};
    uint8_t palette[][3] = {{0, 0, 0}};
    size_t palette_size = 1;
    const uint8_t* result = closest_color(target, palette, palette_size);

    int passed = (result != NULL && result == palette[0]);
    printf("test_closest_color_single: %s\n", passed ? "PASSED" : "FAILED");
}

void test_closest_color_empty() {
    uint8_t target[3] = {0, 0, 0};
    uint8_t (*palette)[3] = NULL;
    size_t palette_size = 0;
    const uint8_t* result = closest_color(target, palette, palette_size);

    int passed = (result == NULL);
    printf("test_closest_color_empty: %s\n", passed ? "PASSED" : "FAILED");
}

int main(void) {
    test_closest_color_basic();
    test_closest_color_single();
    test_closest_color_empty();
    return 0;
}