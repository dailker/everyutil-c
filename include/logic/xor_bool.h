#ifndef LOGIC_XOR_BOOL_H
#define LOGIC_XOR_BOOL_H

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
 * Logical exclusive OR for booleans.
 *
 * @param a First boolean.
 * @param b Second boolean.
 * @return XOR result (0 or 1).
 */
EVERYUTIL_API int xor_bool(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_XOR_BOOL_H