#include "color/color_to_css_variable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *color_to_css_variable(const char *color, const char *var_name) {
    if (!color || !var_name) return NULL;

    // Length: var_name + ": " + color + ";" + '\0'
    size_t len = strlen(var_name) + 2 + strlen(color) + 1 + 1;
    char *result = (char *)malloc(len);
    if (!result) return NULL;

    snprintf(result, len, "%s: %s;", var_name, color);
    return result;
}
