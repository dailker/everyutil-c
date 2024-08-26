#ifndef COLOR_COLOR_WHEEL_POSITION_H
#define COLOR_COLOR_WHEEL_POSITION_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Parses color string to struct color_rgba_t.
 */
typedef struct {
    int r;
    int g;
    int b;
    double a;
} color_rgba_t;

/**
 * Parses a color string (hex or rgb) into color_rgba_t.
 * Returns 1 if success, 0 otherwise.
 */
int parse_color_string(const char *color, color_rgba_t *out_color);

/**
 * Converts RGB to HSL.
 * Input r,g,b in [0,255].
 * Output h,s,l in degrees(0-360), [0,1], [0,1].
 */
typedef struct {
    double h; // hue angle 0-360
    double s; // saturation 0-1
    double l; // lightness 0-1
} hsl_t;

hsl_t rgb_to_hsl(int r, int g, int b);

/**
 * Finds the hue position of a color on the color wheel.
 *
 * @param color Color string (hex or rgb).
 * @return Hue angle (0-360). Returns 0 if parsing fails.
 */
double color_wheel_position(const char *color);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_WHEEL_POSITION_H */
