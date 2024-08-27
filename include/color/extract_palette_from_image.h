#ifndef COLOR_EXTRACT_PALETTE_FROM_IMAGE_H
#define COLOR_EXTRACT_PALETTE_FROM_IMAGE_H

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
 * Extracts a representative color palette from an image.
 *
 * @param data     Pointer to RGB image data (3 bytes per pixel: R, G, B).
 * @param width    Width of the image in pixels.
 * @param height   Height of the image in pixels.
 * @param count    Number of colors to include in the palette.
 * @return         NULL-terminated array of dynamically allocated hex strings (e.g., "#336699").
 *                 Caller must free each string and the array. Returns NULL on error.
 */
EVERYUTIL_API char** extract_palette_from_image(const unsigned char* data, size_t width, size_t height, size_t count);

#ifdef __cplusplus
}
#endif

#endif // COLOR_EXTRACT_PALETTE_FROM_IMAGE_H
