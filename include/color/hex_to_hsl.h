#ifndef COLOR_HEX_TO_HSL_H
#define COLOR_HEX_TO_HSL_H

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

typedef struct {
    double h; // Hue: 0-360 degrees
    double s; // Saturation: 0-100%
    double l; // Lightness: 0-100%
} HSL;

/**
 * Converts a hex color string (e.g. "#ff0080") to HSL.
 *
 * @param hex Null-terminated hex string (#RRGGBB).
 * @param out_hsl Pointer to HSL struct to fill.
 * @return 1 on success, 0 on invalid input.
 */
EVERYUTIL_API int hex_to_hsl(const char* hex, HSL* out_hsl);

#ifdef __cplusplus
}
#endif

#endif // COLOR_HEX_TO_HSL_H
