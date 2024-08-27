#ifndef COLOR_GENERATE_GRADIENT_COLORS_H
#define COLOR_GENERATE_GRADIENT_COLORS_H

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

#include <stddef.h>

/**
 * Generates a color gradient between two hex colors.
 *
 * @param start_hex Start color string in hex (e.g., "#336699").
 * @param end_hex   End color string in hex (e.g., "#ff0080").
 * @param steps     Number of gradient steps (>=2).
 * @return          Array of dynamically allocated hex strings (length = steps).
 *                  Returns NULL on failure. Caller must free each string and the array.
 */
EVERYUTIL_API char** generate_gradient_colors(const char* start_hex, const char* end_hex, size_t steps);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GENERATE_GRADIENT_COLORS_H
