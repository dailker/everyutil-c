#ifndef DATE_DATE_DIFF_IN_BUSINESS_DAYS_H
#define DATE_DATE_DIFF_IN_BUSINESS_DAYS_H

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
 * Counts business days between two dates.
 *
 * @param start Start timestamp.
 * @param end End timestamp.
 * @return Number of business days between dates.
 */
EVERYUTIL_API int date_diff_in_business_days(time_t start, time_t end);

#ifdef __cplusplus
}
#endif

#endif // DATE_DATE_DIFF_IN_BUSINESS_DAYS_H