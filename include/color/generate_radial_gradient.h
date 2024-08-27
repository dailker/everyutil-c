#ifndef COLOR_GENERATE_RADIAL_GRADIENT_H
#define COLOR_GENERATE_RADIAL_GRADIENT_H

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
 * Generates a radial gradient between two hex colors.
 *
 * @param center_hex Hex string of the center color (e.g., "#FFFFFF").
 * @param edge_hex Hex string of the edge color (e.g., "#000000").
 * @param steps Number of gradient steps (>= 2).
 * @return NULL-terminated array of hex strings. NULL on failure.
 *         Caller must free each string and the array.
 */
EVERYUTIL_API char** generate_radial_gradient(const char* center_hex, const char* edge_hex, size_t steps);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GENERATE_RADIAL_GRADIENT_H
