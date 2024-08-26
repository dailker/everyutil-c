#ifndef COLOR_COLOR_TO_CSS_H
#define COLOR_COLOR_TO_CSS_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Converts RGB(A) components to a CSS color string.
 *
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @param a Alpha component (0.0-1.0), pass -1.0 if no alpha.
 * @return Dynamically allocated string with CSS color (caller must free), or NULL on failure.
 */
char *color_to_css(int r, int g, int b, double a);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_TO_CSS_H */