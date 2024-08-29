#ifndef DATE_ADD_BUSINESS_DAYS_H
#define DATE_ADD_BUSINESS_DAYS_H

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
 * Adds N business days to a date, skipping weekends.
 *
 * @param timestamp Start timestamp.
 * @param days Number of business days to add.
 * @return Resulting timestamp after adding business days.
 */
EVERYUTIL_API time_t add_business_days(time_t timestamp, int days);

#ifdef __cplusplus
}
#endif

#endif // DATE_ADD_BUSINESS_DAYS_H