#ifndef COLOR_CLOSEST_COLOR_H
#define COLOR_CLOSEST_COLOR_H

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
#include <stddef.h>

/**
 * Finds the closest color in a palette to the target color using Euclidean distance.
 * @param target The target RGB color (array of 3 uint8_t values).
 * @param palette Array of RGB colors (each an array of 3 uint8_t values).
 * @param palette_size Number of colors in the palette.
 * @return Pointer to the closest color in the palette, or NULL on error.
 *         The returned pointer points to the palette’s color (not a copy).
 */
EVERYUTIL_API const uint8_t* closest_color(const uint8_t target[3], const uint8_t palette[][3], size_t palette_size);

#ifdef __cplusplus
}
#endif

#endif // COLOR_CLOSEST_COLOR_H