#include "color/find_nearest_named_color.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

typedef struct {
    const char* name;
    const char* hex;
    unsigned char r, g, b;
} NamedColor;

static unsigned char hex2byte(const char* s) {
    unsigned int x = 0;
    sscanf(s, "%2x", &x);
    return (unsigned char)x;
}

static int parse_hex(const char* hex, unsigned char* r, unsigned char* g, unsigned char* b) {
    if (!hex || hex[0] != '#') return 0;
    size_t len = strlen(hex);
    if (len == 7) { // #RRGGBB
        *r = hex2byte(hex + 1);
        *g = hex2byte(hex + 3);
        *b = hex2byte(hex + 5);
        return 1;
    } else if (len == 4) { // #RGB
        *r = hex2byte((char[]){hex[1], hex[1], 0});
        *g = hex2byte((char[]){hex[2], hex[2], 0});
        *b = hex2byte((char[]){hex[3], hex[3], 0});
        return 1;
    }
    return 0;
}

static int color_distance_sq(unsigned char r1, unsigned char g1, unsigned char b1,
                             unsigned char r2, unsigned char g2, unsigned char b2) {
    int dr = (int)r1 - (int)r2;
    int dg = (int)g1 - (int)g2;
    int db = (int)b1 - (int)b2;
    return dr * dr + dg * dg + db * db;
}

// Minimal CSS named color list. Expand as needed.
static const NamedColor named_colors[] = {
    {"black",   "#000000", 0x00, 0x00, 0x00},
    {"white",   "#ffffff", 0xff, 0xff, 0xff},
    {"red",     "#ff0000", 0xff, 0x00, 0x00},
    {"green",   "#008000", 0x00, 0x80, 0x00},
    {"blue",    "#0000ff", 0x00, 0x00, 0xff},
    {"skyblue", "#87ceeb", 0x87, 0xce, 0xeb},
    {"gray",    "#808080", 0x80, 0x80, 0x80},
    {"yellow",  "#ffff00", 0xff, 0xff, 0x00},
    {"cyan",    "#00ffff", 0x00, 0xff, 0xff},
    {"magenta", "#ff00ff", 0xff, 0x00, 0xff},
    // Add more named colors as needed
};

#define NAMED_COLOR_COUNT (sizeof(named_colors) / sizeof(named_colors[0]))

EVERYUTIL_API char* find_nearest_named_color(const char* hex_color) {
    if (!hex_color) return NULL;

    unsigned char r, g, b;
    if (!parse_hex(hex_color, &r, &g, &b)) return NULL;

    int min_dist = INT_MAX;
    const char* nearest_hex = NULL;

    for (size_t i = 0; i < NAMED_COLOR_COUNT; ++i) {
        const NamedColor* nc = &named_colors[i];
        int dist = color_distance_sq(r, g, b, nc->r, nc->g, nc->b);
        if (dist < min_dist) {
            min_dist = dist;
            nearest_hex = nc->hex;
        }
    }

    if (!nearest_hex) return NULL;

    size_t len = strlen(nearest_hex);
    char* result = (char*)malloc(len + 1);
    if (!result) return NULL;
    strcpy(result, nearest_hex);
    return result;
}