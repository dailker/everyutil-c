#ifndef COLOR_LIST_NAMED_COLORS_H
#define COLOR_LIST_NAMED_COLORS_H

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
 * Represents a named color with name and hex string.
 */
typedef struct {
    const char* name;
    const char* hex;
} named_color_t;

/**
 * Returns pointer to static array of named colors.
 * The array length is stored in out_count.
 *
 * @param out_count Pointer to size_t to receive the number of colors.
 * @return Pointer to a static array of named_color_t.
 */
EVERYUTIL_API const named_color_t* listNamedColors(size_t* out_count);

#ifdef __cplusplus
}
#endif

#endif // COLOR_LIST_NAMED_COLORS_H