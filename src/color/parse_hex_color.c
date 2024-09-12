#include "color/parse_hex_color.h"
#include <string.h>
#include <ctype.h>
static int hex_digit_to_int(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    return -1;
}
EVERYUTIL_API int parse_hex_color(const char* hex_color, unsigned char* r, unsigned char* g, unsigned char* b) {
    if (!hex_color || !r || !g || !b) return 0;
    size_t len = strlen(hex_color);
    if (len != 7 && len != 4) return 0;
    if (hex_color[0] != '#') return 0;
    if (len == 7) {
        int r1 = hex_digit_to_int(hex_color[1]);
        int r2 = hex_digit_to_int(hex_color[2]);
        int g1 = hex_digit_to_int(hex_color[3]);
        int g2 = hex_digit_to_int(hex_color[4]);
        int b1 = hex_digit_to_int(hex_color[5]);
        int b2 = hex_digit_to_int(hex_color[6]);
        if (r1 < 0 || r2 < 0 || g1 < 0 || g2 < 0 || b1 < 0 || b2 < 0) return 0;
        *r = (unsigned char)((r1 << 4) | r2);
        *g = (unsigned char)((g1 << 4) | g2);
        *b = (unsigned char)((b1 << 4) | b2);
        return 1;
    } else {
        int r1 = hex_digit_to_int(hex_color[1]);
        int g1 = hex_digit_to_int(hex_color[2]);
        int b1 = hex_digit_to_int(hex_color[3]);
        if (r1 < 0 || g1 < 0 || b1 < 0) return 0;
        *r = (unsigned char)((r1 << 4) | r1);
        *g = (unsigned char)((g1 << 4) | g1);
        *b = (unsigned char)((b1 << 4) | b1);
        return 1;
    }
}