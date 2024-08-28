#ifndef PARSE_COLOR_STRING_H
#define PARSE_COLOR_STRING_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
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
    int r;
    int g;
    int b;
    double a;
} color_rgba_t;
EVERYUTIL_API int parse_color_string(const char *str, color_rgba_t *out_color);
#ifdef __cplusplus
}
#endif
#endif