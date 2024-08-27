#ifndef GET_BRIGHTNESS_H
#define GET_BRIGHTNESS_H
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
EVERYUTIL_API int get_brightness(unsigned char r, unsigned char g, unsigned char b);
#ifdef __cplusplus
}
#endif
#endif