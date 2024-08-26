#ifndef COLOR_ADJUST_ALPHA_H
#define COLOR_ADJUST_ALPHA_H

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
 * Adjusts the alpha of a hex or rgb color string.
 *
 * @param color  The color string (e.g. "#336699" or "rgb(51,102,153)").
 * @param alpha  The alpha value (0.0 to 1.0).
 * @return       New rgba() string. Caller must free it.
 */
EVERYUTIL_API char* adjust_alpha(const char* color, double alpha);

#ifdef __cplusplus
}
#endif

#endif // COLOR_ADJUST_ALPHA_H
