#ifndef LOGIC_COERCE_TO_BOOL_H
#define LOGIC_COERCE_TO_BOOL_H

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
 * Converts string to boolean reliably.
 *
 * @param str String to convert.
 * @param strict Use strict conversion rules.
 * @return Boolean value (0 or 1).
 */
EVERYUTIL_API int coerce_to_bool(const char* str, int strict);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_COERCE_TO_BOOL_H