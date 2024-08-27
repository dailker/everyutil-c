#ifndef COLOR_HEX_TO_RGB_H
#define COLOR_HEX_TO_RGB_H

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

typedef struct {
    int r; /**< Red component (0-255) */
    int g; /**< Green component (0-255) */
    int b; /**< Blue component (0-255) */
} RGB;

/**
 * Converts a hex color string (#RRGGBB) to an RGB struct.
 *
 * @param hex Null-terminated string with hex color (7 chars: #RRGGBB).
 * @param out_rgb Pointer to RGB struct to fill on success.
 * @return 1 on success, 0 if invalid input.
 */
EVERYUTIL_API int hex_to_rgb(const char* hex, RGB* out_rgb);

#ifdef __cplusplus
}
#endif

#endif // COLOR_HEX_TO_RGB_H