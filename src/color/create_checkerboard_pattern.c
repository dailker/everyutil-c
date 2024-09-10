#include "color/create_checkerboard_pattern.h"
#include <stdlib.h>
#include <string.h>

static char *strdup_safe(const char *s) {
    if (!s) return NULL;
    size_t len = strlen(s);
    char *copy = (char *)malloc(len + 1);
    if (!copy) return NULL;
    memcpy(copy, s, len + 1);
    return copy;
}

char ***create_checkerboard_pattern(const char *color1, const char *color2, size_t size) {
    if (!color1 || !color2 || size == 0) return NULL;

    char ***pattern = (char ***)malloc(size * sizeof(char **));
    if (!pattern) return NULL;

    for (size_t i = 0; i < size; i++) {
        pattern[i] = (char **)malloc(size * sizeof(char *));
        if (!pattern[i]) {
            // Free previously allocated rows
            for (size_t k = 0; k < i; k++) {
                free(pattern[k]);
            }
            free(pattern);
            return NULL;
        }
        for (size_t j = 0; j < size; j++) {
            const char *color = ((i + j) % 2 == 0) ? color1 : color2;
            pattern[i][j] = strdup_safe(color);
            if (!pattern[i][j]) {
                // Free allocated strings and arrays so far
                for (size_t m = 0; m < j; m++) free(pattern[i][m]);
                for (size_t k = 0; k < i; k++) {
                    for (size_t n = 0; n < size; n++) free(pattern[k][n]);
                    free(pattern[k]);
                }
                free(pattern[i]);
                free(pattern);
                return NULL;
            }
        }
    }
    return pattern;
}

void free_checkerboard_pattern(char ***pattern, size_t size) {
    if (!pattern) return;
    for (size_t i = 0; i < size; i++) {
        if (pattern[i]) {
            for (size_t j = 0; j < size; j++) {
                free(pattern[i][j]);
            }
            free(pattern[i]);
        }
    }
    free(pattern);
}