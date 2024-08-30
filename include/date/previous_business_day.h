#ifndef DATE_PREVIOUS_BUSINESS_DAY_H
#define DATE_PREVIOUS_BUSINESS_DAY_H

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
 * Finds the previous business day before a given date, skipping weekends.
 *
 * @param timestamp Input timestamp.
 * @return Previous business day timestamp.
 */
EVERYUTIL_API time_t previous_business_day(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_PREVIOUS_BUSINESS_DAY_H