#ifndef COLOR_GET_LUMINANCE_H
#define COLOR_GET_LUMINANCE_H

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
 * Calculates the relative luminance of a color for contrast calculations.
 *
 * @param color A null-terminated string representing the color (hex or rgb).
 * @return      The relative luminance value (0.0 - 1.0). Returns 0.0 on invalid input.
 */
EVERYUTIL_API double get_luminance(const char* color);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GET_LUMINANCE_H