#ifndef COLOR_DARKEN_H
#define COLOR_DARKEN_H

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
 * Darkens a hex color by a given amount.
 *
 * @param color Hex color string (e.g. "#336699").
 * @param amount Darken amount (0.0 - 1.0).
 * @return Newly allocated darkened hex color string (caller must free), or NULL on failure.
 */
EVERYUTIL_API char *darken(const char *color, double amount);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_DARKEN_H */
