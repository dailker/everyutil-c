#ifndef COLOR_GET_COLOR_NAME_H
#define COLOR_GET_COLOR_NAME_H

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
 * Returns a human-readable name for a color (e.g. "Sky Blue").
 *
 * @param color A null-terminated string representing the color (hex or rgb).
 * @return Pointer to a static string with the color name or closest match.
 *         Returns NULL if input invalid.
 */
EVERYUTIL_API const char* get_color_name(const char* color);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GET_COLOR_NAME_H