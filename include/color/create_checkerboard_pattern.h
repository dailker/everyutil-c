#ifndef COLOR_CREATE_CHECKERBOARD_PATTERN_H
#define COLOR_CREATE_CHECKERBOARD_PATTERN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * Creates a checkerboard pattern represented as a 2D array of strings.
 *
 * @param color1 First color string.
 * @param color2 Second color string.
 * @param size Size of the checkerboard (number of squares per row and column).
 * @return Pointer to an array of pointers to string arrays (2D array).
 *         Returns NULL on failure. Caller must free all allocated memory.
 */
char ***create_checkerboard_pattern(const char *color1, const char *color2, size_t size);

/**
 * Frees memory allocated by create_checkerboard_pattern.
 *
 * @param pattern The 2D array returned by create_checkerboard_pattern.
 * @param size Size parameter passed to create_checkerboard_pattern.
 */
void free_checkerboard_pattern(char ***pattern, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_CREATE_CHECKERBOARD_PATTERN_H */
