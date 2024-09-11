#include "color/get_color_name.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Reuse color struct and parseColorString from adjust_alpha.c
typedef struct {
    int r, g, b;
} Color;

static int parse_hex_digit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    return -1;
}

static int parse_hex_component(const char* s) {
    int hi = parse_hex_digit(s[0]);
    int lo = parse_hex_digit(s[1]);
    if (hi == -1 || lo == -1) return -1;
    return (hi << 4) + lo;
}

static int parse_rgb_component(const char* s, int* value) {
    while (isspace((unsigned char)*s)) ++s;
    char* end;
    long val = strtol(s, &end, 10);
    if (end == s || val < 0 || val > 255) return 0;
    *value = (int)val;
    return 1;
}

static int parseColorString(const char* str, Color* out) {
    if (!str || !out) return 0;

    if (str[0] == '#' && strlen(str) == 7) {
        int r = parse_hex_component(str + 1);
        int g = parse_hex_component(str + 3);
        int b = parse_hex_component(str + 5);
        if (r < 0 || g < 0 || b < 0) return 0;
        out->r = r;
        out->g = g;
        out->b = b;
        return 1;
    }

    if (strncmp(str, "rgb(", 4) == 0) {
        const char* p = str + 4;
        int r, g, b;

        if (!parse_rgb_component(p, &r)) return 0;
        p = strchr(p, ','); if (!p) return 0; ++p;

        if (!parse_rgb_component(p, &g)) return 0;
        p = strchr(p, ','); if (!p) return 0; ++p;

        if (!parse_rgb_component(p, &b)) return 0;
        p = strchr(p, ')'); if (!p) return 0;

        out->r = r;
        out->g = g;
        out->b = b;
        return 1;
    }

    return 0;
}

// Named colors database (subset example)
typedef struct {
    const char* name;
    Color color;
} NamedColor;

static const NamedColor named_colors[] = {
    {"Black",      {0, 0, 0}},
    {"White",      {255, 255, 255}},
    {"Red",        {255, 0, 0}},
    {"Lime",       {0, 255, 0}},
    {"Blue",       {0, 0, 255}},
    {"Yellow",     {255, 255, 0}},
    {"Cyan",       {0, 255, 255}},
    {"Magenta",    {255, 0, 255}},
    {"Silver",     {192, 192, 192}},
    {"Gray",       {128, 128, 128}},
    {"Maroon",     {128, 0, 0}},
    {"Olive",      {128, 128, 0}},
    {"Green",      {0, 128, 0}},
    {"Purple",     {128, 0, 128}},
    {"Teal",       {0, 128, 128}},
    {"Navy",       {0, 0, 128}},
    {"Sky Blue",   {135, 206, 235}}, // #87CEEB example
    // Add more as needed
};

static double color_distance_squared(Color a, Color b) {
    int dr = a.r - b.r;
    int dg = a.g - b.g;
    int db = a.b - b.b;
    return (double)(dr*dr + dg*dg + db*db);
}

EVERYUTIL_API const char* get_color_name(const char* color) {
    Color c;
    if (!parseColorString(color, &c)) {
        return NULL;
    }

    const NamedColor* nearest = NULL;
    double min_dist = -1.0;

    for (size_t i = 0; i < sizeof(named_colors)/sizeof(named_colors[0]); ++i) {
        double dist = color_distance_squared(c, named_colors[i].color);
        if (nearest == NULL || dist < min_dist) {
            nearest = &named_colors[i];
            min_dist = dist;
        }
    }

    return nearest ? nearest->name : NULL;
}
