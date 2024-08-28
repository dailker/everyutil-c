#ifndef COLOR_HSL_TO_HEX_H
#define COLOR_HSL_TO_HEX_H

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

/**
 * Converts HSL color values to a hex color string.
 *
 * @param h Hue angle in degrees (0-360).
 * @param s Saturation percentage (0-100).
 * @param l Lightness percentage (0-100).
 * @return A newly allocated string in the format "#RRGGBB" (caller must free),
 *         or NULL on failure.
 */
EVERYUTIL_API char* hsl_to_hex(double h, double s, double l);

#ifdef __cplusplus
}
#endif

#endif // COLOR_HSL_TO_HEX_H
