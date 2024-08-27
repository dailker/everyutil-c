#ifndef COLOR_CONTRAST_RATIO_H
#define COLOR_CONTRAST_RATIO_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Calculates the WCAG contrast ratio between two colors.
 *
 * @param color1 First color string (hex or rgb).
 * @param color2 Second color string (hex or rgb).
 * @return Contrast ratio as a double. Returns -1.0 on error.
 */
double contrast_ratio(const char *color1, const char *color2);

/**
 * Returns relative luminance of a color string.
 * Should be implemented separately.
 *
 * @param color Color string.
 * @return Luminance as double (0.0 to 1.0), or -1.0 on failure.
 */
double get_luminance(const char *color);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_CONTRAST_RATIO_H */
