#ifndef HSL_TO_RGB_H
#define HSL_TO_RGB_H
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
    int r, g, b;
} RGB;
EVERYUTIL_API int hsl_to_rgb(double h, double s, double l, RGB* out_rgb);
#ifdef __cplusplus
}
#endif
#endif