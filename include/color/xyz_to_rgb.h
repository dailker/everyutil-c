#ifndef XYZ_TO_RGB_H
#define XYZ_TO_RGB_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#include "color/rgb_to_xyz.h"
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
EVERYUTIL_API RGB xyz_to_rgb(ColorXYZ xyz);
#ifdef __cplusplus
}
#endif
#endif