#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/generate_palette.h"

int main(void) {
    char **palette;
    
    // Test complementary palette
    palette = generate_palette("#ff0000", "complementary");
    if (palette && palette[0] && palette[1] && palette[2] == NULL) {
        printf("complementary palette: PASSED\n");
    } else {
        printf("complementary palette: FAILED\n");
    }
    if (palette) {
        for (int i = 0; palette[i]; i++) free(palette[i]);
        free(palette);
    }
    
    // Test triadic palette
    palette = generate_palette("#ff0000", "triadic");
    if (palette && palette[0] && palette[1] && palette[2] && palette[3] == NULL) {
        printf("triadic palette: PASSED\n");
    } else {
        printf("triadic palette: FAILED\n");
    }
    if (palette) {
        for (int i = 0; palette[i]; i++) free(palette[i]);
        free(palette);
    }
    
    // Test analogous palette
    palette = generate_palette("#ff0000", "analogous");
    if (palette && palette[0] && palette[1] && palette[2] && palette[3] == NULL) {
        printf("analogous palette: PASSED\n");
    } else {
        printf("analogous palette: FAILED\n");
    }
    if (palette) {
        for (int i = 0; palette[i]; i++) free(palette[i]);
        free(palette);
    }
    
    // Test invalid input
    palette = generate_palette("invalid", "complementary");
    if (palette == NULL) {
        printf("invalid color: PASSED\n");
    } else {
        printf("invalid color: FAILED\n");
        for (int i = 0; palette[i]; i++) free(palette[i]);
        free(palette);
    }
    
    return 0;
}