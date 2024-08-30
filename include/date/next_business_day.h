#ifndef DATE_NEXT_BUSINESS_DAY_H
#define DATE_NEXT_BUSINESS_DAY_H

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
 * Finds the next business day after a given date, skipping weekends.
 *
 * @param timestamp Input timestamp.
 * @return Next business day timestamp.
 */
EVERYUTIL_API time_t next_business_day(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_NEXT_BUSINESS_DAY_H