#ifndef COLOR_CREATE_STRIPED_PATTERN_H
#define COLOR_CREATE_STRIPED_PATTERN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * Creates a striped pattern array of colors.
 *
 * @param colors Array of color strings.
 * @param colors_count Number of colors in the colors array.
 * @param width Width of each stripe (number of repeats per color).
 * @param out_size Pointer to size_t to receive length of the returned array.
 * @return Dynamically allocated array of strings representing the pattern.
 *         Returns NULL on failure. Caller must free using free_striped_pattern.
 */
char **create_striped_pattern(const char **colors, size_t colors_count, size_t width, size_t *out_size);

/**
 * Frees memory allocated by create_striped_pattern.
 *
 * @param pattern The array returned by create_striped_pattern.
 * @param size The size of the array.
 */
void free_striped_pattern(char **pattern, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_CREATE_STRIPED_PATTERN_H */
