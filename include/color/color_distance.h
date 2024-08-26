#ifndef COLOR_DISTANCE_H
#define COLOR_DISTANCE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stdint.h>

/**
 * Computes the Euclidean distance between two RGB colors.
 * @param color1 First RGB color (array of 3 uint8_t values).
 * @param color2 Second RGB color (array of 3 uint8_t values).
 * @return The Euclidean distance between the colors.
 *         Returns -1.0 on error (e.g., NULL input).
 */
EVERYUTIL_API double color_distance(const uint8_t color1[3], const uint8_t color2[3]);

#ifdef __cplusplus
}
#endif

#endif // COLOR_DISTANCE_H