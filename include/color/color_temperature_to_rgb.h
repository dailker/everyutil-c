#ifndef COLOR_COLOR_TEMPERATURE_TO_RGB_H
#define COLOR_COLOR_TEMPERATURE_TO_RGB_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Converts color temperature in Kelvin to RGB.
 *
 * @param temp_kelvin Color temperature in Kelvin.
 * @param out_r Pointer to int for red component [0-255].
 * @param out_g Pointer to int for green component [0-255].
 * @param out_b Pointer to int for blue component [0-255].
 */
void color_temperature_to_rgb(int temp_kelvin, int *out_r, int *out_g, int *out_b);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_COLOR_TEMPERATURE_TO_RGB_H */
