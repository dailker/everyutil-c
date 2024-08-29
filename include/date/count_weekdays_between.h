#ifndef DATE_COUNT_WEEKDAYS_BETWEEN_H
#define DATE_COUNT_WEEKDAYS_BETWEEN_H

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
 * Counts how many weekdays fall between two dates (inclusive).
 *
 * @param start Start timestamp.
 * @param end End timestamp.
 * @return Number of weekdays between dates.
 */
EVERYUTIL_API int count_weekdays_between(time_t start, time_t end);

#ifdef __cplusplus
}
#endif

#endif // DATE_COUNT_WEEKDAYS_BETWEEN_H