#ifndef LOGIC_TOGGLE_BOOL_H
#define LOGIC_TOGGLE_BOOL_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

/**
 * Flips a boolean value.
 *
 * @param b Boolean value (0=false, non-zero=true).
 * @return Flipped boolean (0 or 1).
 */
EVERYUTIL_API int toggle_bool(int b);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_TOGGLE_BOOL_H