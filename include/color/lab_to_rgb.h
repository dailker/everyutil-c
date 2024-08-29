#ifndef COLOR_LAB_TO_RGB_H
#define COLOR_LAB_TO_RGB_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stdint.h>

/**
 * RGB struct representing red, green, and blue components (0-255).
 */
typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;

/**
 * Converts CIELAB color to RGB.
 *
 * @param l Lightness (0-100).
 * @param a Green-Red (-128 to 127).
 * @param b Blue-Yellow (-128 to 127).
 * @return RGB struct with r, g, b in [0,255].
 */
EVERYUTIL_API rgb_t labToRgb(double l, double a, double b);

#ifdef __cplusplus
}
#endif

#endif // COLOR_LAB_TO_RGB_H
