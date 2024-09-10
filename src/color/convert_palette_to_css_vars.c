#include "color/convert_palette_to_css_vars.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert_palette_to_css_vars(const char **palette, size_t count, const char *prefix) {
    if (!palette || !prefix) return NULL;

    size_t prefix_len = strlen(prefix);
    size_t total_len = 10; // ":root { " + " }" + '\0'
    for (size_t i = 0; i < count; i++) {
        if (!palette[i]) return NULL;
        total_len += prefix_len + 20 + strlen(palette[i]);
    }

    char *result = (char *)malloc(total_len);
    if (!result) return NULL;

    strcpy(result, ":root { ");
    char *p = result + strlen(result);

    for (size_t i = 0; i < count; i++) {
        int written = sprintf(p, "%s-%zu: %s; ", prefix, i, palette[i]);
        if (written < 0) {
            free(result);
            return NULL;
        }
        p += written;
    }

    strcpy(p, "}");
    return result;
}
