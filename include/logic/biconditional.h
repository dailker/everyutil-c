#ifndef LOGIC_BICONDITIONAL_H
#define LOGIC_BICONDITIONAL_H

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
 * Logical equivalence (A iff B).
 *
 * @param a First boolean value.
 * @param b Second boolean value.
 * @return 1 if equivalent, 0 otherwise.
 */
EVERYUTIL_API int biconditional(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BICONDITIONAL_H