#ifndef DATE_END_OF_MONTH_H
#define DATE_END_OF_MONTH_H

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
 * Gets the end of the month for a date.
 *
 * @param timestamp Input timestamp.
 * @return Timestamp at end of month (23:59:59).
 */
EVERYUTIL_API time_t end_of_month(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_END_OF_MONTH_H