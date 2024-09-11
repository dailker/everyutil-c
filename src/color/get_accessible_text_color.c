#include "color/get_accessible_text_color.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static int parse_hex_rgb(const char* hex, unsigned char* r, unsigned char* g, unsigned char* b) {
    if (!hex || strlen(hex) != 7 || hex[0] != '#') return 0;
    unsigned int ri, gi, bi;
    if (sscanf(hex + 1, "%2x%2x%2x", &ri, &gi, &bi) != 3) return 0;
    *r = (unsigned char)ri;
    *g = (unsigned char)gi;
    *b = (unsigned char)bi;
    return 1;
}

static int is_color_dark(const char* hex) {
    unsigned char r, g, b;
    if (!parse_hex_rgb(hex, &r, &g, &b)) return 0;

    // Calculate luminance using WCAG formula
    double dr = r / 255.0;
    double dg = g / 255.0;
    double db = b / 255.0;

    double luminance = 0.2126 * dr + 0.7152 * dg + 0.0722 * db;
    return luminance < 0.5;
}

EVERYUTIL_API const char* get_accessible_text_color(const char* background_hex) {
    if (!background_hex) return NULL;
    return is_color_dark(background_hex) ? "#fff" : "#000";
}
