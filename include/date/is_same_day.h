#ifndef DATE_IS_SAME_DAY_H
#define DATE_IS_SAME_DAY_H

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

#include <time.h>

/**
 * Checks if two dates fall on the same calendar day.
 *
 * @param a First timestamp.
 * @param b Second timestamp.
 * @return 1 if same day, 0 otherwise.
 */
EVERYUTIL_API int is_same_day(time_t a, time_t b);

#ifdef __cplusplus
}
#endif

#endif // DATE_IS_SAME_DAY_H