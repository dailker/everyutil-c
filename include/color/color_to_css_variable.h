#ifndef COLOR_COLOR_TO_CSS_VARIABLE_H
#define COLOR_COLOR_TO_CSS_VARIABLE_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Generates a CSS variable declaration string.
 *
 * @param color Color string (e.g. "#336699" or "rgb(51,102,153)").
 * @param var_name CSS variable name (e.g. "--main-color").
 * @return Dynamically allocated string with CSS variable declaration (caller must free),
 *         or NULL on allocation failure.
 */
char *color_to_css_variable(const char *color, const char *var_name);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_TO_CSS_VARIABLE_H */
