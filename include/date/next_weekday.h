#ifndef DATE_NEXT_WEEKDAY_H
#define DATE_NEXT_WEEKDAY_H

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
 * Finds the next date that is a specific weekday.
 *
 * @param timestamp Start timestamp.
 * @param weekday Target weekday (0=Sunday, 6=Saturday).
 * @return Next occurrence of the weekday.
 */
EVERYUTIL_API time_t next_weekday(time_t timestamp, int weekday);

#ifdef __cplusplus
}
#endif

#endif // DATE_NEXT_WEEKDAY_H