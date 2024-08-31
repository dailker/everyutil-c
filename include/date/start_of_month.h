#ifndef DATE_START_OF_MONTH_H
#define DATE_START_OF_MONTH_H

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
 * Gets the start of the month for a date.
 *
 * @param timestamp Input timestamp.
 * @return Timestamp at start of month (00:00:00).
 */
EVERYUTIL_API time_t start_of_month(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_START_OF_MONTH_H