#ifndef COLOR_LIGHTEN_H
#define COLOR_LIGHTEN_H

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
 * Lightens a hex color string by an amount.
 *
 * @param color Null-terminated hex color string, e.g. "#336699"
 * @param amount Amount to lighten (0.0 to 1.0)
 * @return Newly allocated hex color string "#rrggbb" (caller must free), or NULL on failure.
 */
EVERYUTIL_API char* lighten(const char* color, double amount);

#ifdef __cplusplus
}
#endif

#endif // COLOR_LIGHTEN_H