#ifndef VECTOR_TO_COLOR_H
#define VECTOR_TO_COLOR_H
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
} Vector3;
EVERYUTIL_API char *vector_to_color(const Vector3 *vector);
#ifdef __cplusplus
}
#endif
#endif