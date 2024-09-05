#ifndef LOGIC_IS_BOOLEAN_LIKE_H
#define LOGIC_IS_BOOLEAN_LIKE_H

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
 * Checks if string behaves like a boolean.
 *
 * @param str String to check.
 * @return 1 if boolean-like, 0 otherwise.
 */
EVERYUTIL_API int is_boolean_like(const char* str);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IS_BOOLEAN_LIKE_H