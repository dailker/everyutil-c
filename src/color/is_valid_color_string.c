#include "color/is_valid_color_string.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Helper: Check if char is hex digit
static bool is_hex_digit(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}

// Validate hex color (#RGB or #RRGGBB)
static bool validate_hex_color(const char* s) {
    size_t len = strlen(s);
    if (len != 4 && len != 7) return false;
    if (s[0] != '#') return false;
    for (size_t i = 1; i < len; ++i) {
        if (!is_hex_digit(s[i])) return false;
    }
    return true;
}

// Skip whitespace characters
static const char* skip_spaces(const char* s) {
    while (*s && isspace((unsigned char)*s)) s++;
    return s;
}

// Parse integer in [0,255], advance pointer
static bool parse_0_255(const char** ps, int* out_val) {
    const char* s = *ps;
    s = skip_spaces(s);
    char* endptr = NULL;
    long val = strtol(s, &endptr, 10);
    if (endptr == s || val < 0 || val > 255) return false;
    *out_val = (int)val;
    *ps = endptr;
    return true;
}

// Parse float in [0,1], advance pointer
static bool parse_0_1_float(const char** ps, float* out_val) {
    const char* s = *ps;
    s = skip_spaces(s);
    char* endptr = NULL;
    float val = strtof(s, &endptr);
    if (endptr == s || val < 0.0f || val > 1.0f) return false;
    *out_val = val;
    *ps = endptr;
    return true;
}

// Validate rgb(r,g,b) or rgba(r,g,b,a)
static bool validate_rgb_func(const char* s) {
    // s points at 'r' of "rgb" or "rgba"
    bool is_rgba = false;
    if (strncmp(s, "rgb(", 4) == 0) {
        s += 4;
    } else if (strncmp(s, "rgba(", 5) == 0) {
        s += 5;
        is_rgba = true;
    } else {
        return false;
    }

    int r,g,b;
    float a = 1.0f;

    if (!parse_0_255(&s, &r)) return false;

    s = skip_spaces(s);
    if (*s != ',') return false;
    s++;
    if (!parse_0_255(&s, &g)) return false;

    s = skip_spaces(s);
    if (*s != ',') return false;
    s++;
    if (!parse_0_255(&s, &b)) return false;

    if (is_rgba) {
        s = skip_spaces(s);
        if (*s != ',') return false;
        s++;
        if (!parse_0_1_float(&s, &a)) return false;
    }

    s = skip_spaces(s);
    if (*s != ')') return false;
    s++;

    s = skip_spaces(s);
    return *s == '\0'; // no trailing garbage
}

EVERYUTIL_API bool is_valid_color_string(const char* str) {
    if (!str) return false;

    // Check hex color first
    if (str[0] == '#') {
        return validate_hex_color(str);
    }

    // Check rgb or rgba functions
    if (strncmp(str, "rgb", 3) == 0) {
        return validate_rgb_func(str);
    }

    // Could extend here for hsl(), hsla() if needed

    return false;
}