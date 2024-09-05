#ifndef LOGIC_IS_FALSY_H
#define LOGIC_IS_FALSY_H

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
 * Checks if value is falsy (zero).
 *
 * @param val Value to check.
 * @return 1 if falsy, 0 otherwise.
 */
EVERYUTIL_API int is_falsy(int val);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IS_FALSY_H