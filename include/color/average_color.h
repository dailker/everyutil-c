#ifndef COLOR_AVERAGE_COLOR_H
#define COLOR_AVERAGE_COLOR_H

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
 * Computes the average RGB color from an array of colors.
 * @param colors Array of RGB colors (each an array of 3 uint8_t values).
 * @param count Number of colors in the array.
 * @param out_count Pointer to store the number of colors averaged.
 * @return A dynamically allocated array of 3 uint8_t values representing the average color.
 *         Returns NULL on error (e.g., NULL input or count == 0).
 * Caller must free the returned array.
 */
EVERYUTIL_API uint8_t* average_color(uint8_t colors[][3], size_t count, size_t* out_count);

#ifdef __cplusplus
}
#endif

#endif // COLOR_AVERAGE_COLOR_H