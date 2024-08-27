#ifndef COLOR_CONVERT_PALETTE_TO_CSS_VARS_H
#define COLOR_CONVERT_PALETTE_TO_CSS_VARS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * Converts a palette of colors to CSS variables string.
 *
 * @param palette Array of color strings.
 * @param count Number of colors in the palette.
 * @param prefix CSS variable prefix (e.g., "--color").
 * @return Newly allocated string containing CSS variables (caller must free), or NULL on failure.
 */
char *convert_palette_to_css_vars(const char **palette, size_t count, const char *prefix);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_CONVERT_PALETTE_TO_CSS_VARS_H */
