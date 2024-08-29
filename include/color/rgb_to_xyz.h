#ifndef RGB_TO_XYZ_H
#define RGB_TO_XYZ_H
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
    double x, y, z;
} ColorXYZ;
EVERYUTIL_API ColorXYZ rgb_to_xyz(int r, int g, int b);
#ifdef __cplusplus
}
#endif
#endif