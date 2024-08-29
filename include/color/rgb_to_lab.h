#ifndef COLOR_RGB_TO_LAB_H
#define COLOR_RGB_TO_LAB_H

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

/** LAB color struct */
typedef struct {
    double l;
    double a;
    double b;
} ColorLab;

/**
 * Converts RGB (0-255) to CIELAB color space.
 *
 * @param r Red component (0-255).
 * @param g Green component (0-255).
 * @param b Blue component (0-255).
 * @return ColorLab struct with l, a, b values.
 */
EVERYUTIL_API ColorLab rgb_to_lab(int r, int g, int b);

#ifdef __cplusplus
}
#endif

#endif // COLOR_RGB_TO_LAB_H
