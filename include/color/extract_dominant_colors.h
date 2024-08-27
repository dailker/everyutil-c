#ifndef COLOR_EXTRACT_DOMINANT_COLORS_H
#define COLOR_EXTRACT_DOMINANT_COLORS_H

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
 * Extracts the dominant colors from an image using frequency binning.
 *
 * @param data   Pointer to RGB image data (3 bytes per pixel: R, G, B).
 * @param width  Image width in pixels.
 * @param height Image height in pixels.
 * @param count  Number of dominant colors to extract.
 * @return       NULL-terminated array of dynamically allocated hex color strings (caller must free each and the array),
 *               or NULL on failure.
 */
EVERYUTIL_API char** extract_dominant_colors(const unsigned char* data, size_t width, size_t height, size_t count);

#ifdef __cplusplus
}
#endif

#endif // COLOR_EXTRACT_DOMINANT_COLORS_H