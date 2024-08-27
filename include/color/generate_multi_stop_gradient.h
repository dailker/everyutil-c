#ifndef COLOR_GENERATE_MULTI_STOP_GRADIENT_H
#define COLOR_GENERATE_MULTI_STOP_GRADIENT_H

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
 * Generates a gradient with multiple color stops.
 *
 * @param hex_colors Array of color strings (e.g., "#FF0000", "#00FF00").
 * @param color_count Number of input colors.
 * @param stops Number of total steps in the gradient (>= 2).
 * @return NULL-terminated array of dynamically allocated hex strings (length = stops),
 *         or NULL on failure. Caller must free each string and the array.
 */
EVERYUTIL_API char** generate_multi_stop_gradient(const char** hex_colors, size_t color_count, size_t stops);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GENERATE_MULTI_STOP_GRADIENT_H
