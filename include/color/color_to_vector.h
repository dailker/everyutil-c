#ifndef COLOR_COLOR_TO_VECTOR_H
#define COLOR_COLOR_TO_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * RGBA color structure.
 */
typedef struct {
    int r;
    int g;
    int b;
    double a;
} color_rgba_t;

/**
 * Parses a color string to RGBA components.
 * Returns 1 on success, 0 on failure.
 * (You must implement or provide this function separately)
 *
 * @param str Color string (hex, rgb, rgba).
 * @param out_color Pointer to color_rgba_t to fill.
 * @return 1 if successful, 0 otherwise.
 */
int parse_color_string(const char *str, color_rgba_t *out_color);

/**
 * Converts a color string or struct to numeric RGBA vector.
 *
 * @param color_str Color string (hex/rgb) or NULL if using color_obj.
 * @param color_obj Pointer to color_rgba_t struct or NULL if using color_str.
 * @return Dynamically allocated double array of 4 elements (r,g,b,a), or NULL on failure.
 *         Caller must free the array.
 */
double *color_to_vector(const char *color_str, const color_rgba_t *color_obj);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_TO_VECTOR_H */
