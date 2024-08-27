#ifndef COLOR_GET_ACCESSIBLE_TEXT_COLOR_H
#define COLOR_GET_ACCESSIBLE_TEXT_COLOR_H

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
 * Returns black or white hex string for readable text over a background color.
 *
 * @param background_hex The background color in "#RRGGBB" format.
 * @return "#000" or "#fff" depending on contrast. NULL on invalid input.
 */
EVERYUTIL_API const char* get_accessible_text_color(const char* background_hex);

#ifdef __cplusplus
}
#endif

#endif // COLOR_GET_ACCESSIBLE_TEXT_COLOR_H