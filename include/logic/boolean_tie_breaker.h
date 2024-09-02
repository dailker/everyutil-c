#ifndef LOGIC_BOOLEAN_TIE_BREAKER_H
#define LOGIC_BOOLEAN_TIE_BREAKER_H

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
 * Resolves tie between two flags based on backup input.
 *
 * @param primary Primary boolean value.
 * @param secondary Secondary boolean value.
 * @param backup Backup boolean value for tie-breaking.
 * @return Resolved boolean value.
 */
EVERYUTIL_API int boolean_tie_breaker(int primary, int secondary, int backup);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOLEAN_TIE_BREAKER_H