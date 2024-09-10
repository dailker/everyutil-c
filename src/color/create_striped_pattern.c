#include "color/create_striped_pattern.h"
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

char **create_striped_pattern(const char **colors, size_t colors_count, size_t width, size_t *out_size) {
    if (!colors || colors_count == 0 || width == 0 || !out_size) return NULL;

    size_t total_size = colors_count * width;
    char **pattern = (char **)malloc(total_size * sizeof(char *));
    if (!pattern) return NULL;

    size_t idx = 0;
    for (size_t i = 0; i < colors_count; i++) {
        for (size_t j = 0; j < width; j++) {
            pattern[idx] = strdup_safe(colors[i]);
            if (!pattern[idx]) {
                // Free previously allocated strings
                for (size_t k = 0; k < idx; k++) free(pattern[k]);
                free(pattern);
                return NULL;
            }
            idx++;
        }
    }

    *out_size = total_size;
    return pattern;
}

void free_striped_pattern(char **pattern, size_t size) {
    if (!pattern) return;
    for (size_t i = 0; i < size; i++) {
        free(pattern[i]);
    }
    free(pattern);
}
