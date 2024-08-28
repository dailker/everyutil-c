#ifndef PARSE_HEX_COLOR_H
#define PARSE_HEX_COLOR_H
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
EVERYUTIL_API int parse_hex_color(const char* hex_color, unsigned char* r, unsigned char* g, unsigned char* b);
#ifdef __cplusplus
}
#endif
#endif