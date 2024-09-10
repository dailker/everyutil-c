#include "color/adjust_alpha.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

static int hex_to_int(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return -1;
}

static int parse_hex(const char* hex, int* r, int* g, int* b) {
    if (!hex || hex[0] != '#') return 0;
    size_t len = strlen(hex);
    if (len == 7) {
        *r = hex_to_int(hex[1]) * 16 + hex_to_int(hex[2]);
        *g = hex_to_int(hex[3]) * 16 + hex_to_int(hex[4]);
        *b = hex_to_int(hex[5]) * 16 + hex_to_int(hex[6]);
        return 1;
    }
    return 0;
}

static int parse_rgb(const char* rgb, int* r, int* g, int* b) {
    if (!rgb || strncmp(rgb, "rgb(", 4) != 0) return 0;
    
    const char* p = rgb + 4;
    char* end;
    *r = strtol(p, &end, 10);
    if (*end != ',') return 0;
    
    p = end + 1;
    *g = strtol(p, &end, 10);
    if (*end != ',') return 0;
    
    p = end + 1;
    *b = strtol(p, &end, 10);
    if (*end != ')') return 0;
    
    return 1;
}

EVERYUTIL_API char* adjust_alpha(const char* color, double alpha) {
    if (!color || alpha < 0.0 || alpha > 1.0) return NULL;

    int r = 0, g = 0, b = 0;
    if (!parse_hex(color, &r, &g, &b) && !parse_rgb(color, &r, &g, &b)) {
        return NULL;
    }

    char* result = (char*)malloc(32);
    if (!result) return NULL;

    // Print with up to 9 significant digits, trims trailing zeros for integers
snprintf(result, 32, "rgba(%d,%d,%d,%.9g)", r, g, b, alpha);
    return result;
}