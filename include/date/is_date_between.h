#ifndef DATE_IS_DATE_BETWEEN_H
#define DATE_IS_DATE_BETWEEN_H

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
 * Checks if a date lies between two dates inclusive.
 *
 * @param date Date to check.
 * @param start Start date.
 * @param end End date.
 * @return 1 if between, 0 otherwise.
 */
EVERYUTIL_API int is_date_between(time_t date, time_t start, time_t end);

#ifdef __cplusplus
}
#endif

#endif // DATE_IS_DATE_BETWEEN_H