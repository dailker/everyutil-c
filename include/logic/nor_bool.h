#ifndef LOGIC_NOR_BOOL_H
#define LOGIC_NOR_BOOL_H

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
 * NOR logic gate for booleans.
 *
 * @param a First boolean.
 * @param b Second boolean.
 * @return NOR result (0 or 1).
 */
EVERYUTIL_API int nor_bool(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_NOR_BOOL_H