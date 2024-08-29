#ifndef DATE_DATE_DIFFERENCE_IN_WEEKS_H
#define DATE_DATE_DIFFERENCE_IN_WEEKS_H

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
 * Calculates whole weeks difference between two dates.
 *
 * @param a First timestamp.
 * @param b Second timestamp.
 * @return Number of whole weeks between dates.
 */
EVERYUTIL_API int date_difference_in_weeks(time_t a, time_t b);

#ifdef __cplusplus
}
#endif

#endif // DATE_DATE_DIFFERENCE_IN_WEEKS_H