#include "color/extract_colors.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int is_hex_digit(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}



static int starts_with(const char *str, const char *prefix) {
    while (*prefix) {
        if (*str++ != *prefix++) return 0;
    }
    return 1;
}

static char *copy_substring(const char *start, size_t length) {
    char *res = (char *)malloc(length + 1);
    if (!res) return NULL;
    memcpy(res, start, length);
    res[length] = '\0';
    return res;
}

// Extract #hex colors (3-8 hex digits), rgba(), rgb(), hsla(), hsl() colors.
EVERYUTIL_API char **extractColorsFromCss(const char *cssString, size_t *outCount) {
    if (!cssString || !outCount) return NULL;

    *outCount = 0;
    size_t capacity = 8;
    char **results = malloc(capacity * sizeof(char *));
    if (!results) return NULL;

    const char *p = cssString;

    while (*p) {
        // Try to find a color match:
        // 1) Hex color: # followed by 3 to 8 hex digits
        if (*p == '#') {
            const char *start = p;
            p++; // skip #
            size_t hex_len = 0;
            while (hex_len < 8 && is_hex_digit(*p)) {
                hex_len++;
                p++;
            }
            if (hex_len >= 3 && hex_len <= 8) {
                char *color = copy_substring(start, 1 + hex_len);
                if (!color) goto error;
                // Append to results
                if (*outCount >= capacity) {
                    capacity *= 2;
                    char **tmp = realloc(results, capacity * sizeof(char *));
                    if (!tmp) {
                        free(color);
                        goto error;
                    }
                    results = tmp;
                }
                results[(*outCount)++] = color;
                continue; // already moved p forward
            }
            else {
                // Not valid hex color, just continue from next char
                p = start + 1;
                continue;
            }
        }

        // 2) rgba(), rgb(), hsla(), hsl()
        else if (starts_with(p, "rgba(") || starts_with(p, "rgb(") ||
                 starts_with(p, "hsla(") || starts_with(p, "hsl(")) {
            const char *start = p;
            // find closing ')'
            const char *q = p;
            int paren_count = 0;
            while (*q) {
                if (*q == '(') paren_count++;
                else if (*q == ')') {
                    paren_count--;
                    if (paren_count == 0) {
                        q++; // include closing )
                        break;
                    }
                }
                q++;
            }
            if (paren_count == 0) {
                size_t len = q - start;
                char *color = copy_substring(start, len);
                if (!color) goto error;
                if (*outCount >= capacity) {
                    capacity *= 2;
                    char **tmp = realloc(results, capacity * sizeof(char *));
                    if (!tmp) {
                        free(color);
                        goto error;
                    }
                    results = tmp;
                }
                results[(*outCount)++] = color;
                p = q;
                continue;
            }
            else {
                // no closing ), stop searching
                break;
            }
        }
        else {
            p++;
        }
    }

    if (*outCount == 0) {
        free(results);
        return NULL;
    }

    return results;

error:
    for (size_t i = 0; i < *outCount; i++) {
        free(results[i]);
    }
    free(results);
    *outCount = 0;
    return NULL;
}