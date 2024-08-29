#ifndef DATE_DATE_ADD_H
#define DATE_DATE_ADD_H

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
 * Adds days/hours/minutes/seconds to a date.
 *
 * @param timestamp Base timestamp.
 * @param days Days to add.
 * @param hours Hours to add.
 * @param minutes Minutes to add.
 * @param seconds Seconds to add.
 * @return New timestamp with additions.
 */
EVERYUTIL_API time_t date_add(time_t timestamp, int days, int hours, int minutes, int seconds);

#ifdef __cplusplus
}
#endif

#endif // DATE_DATE_ADD_H