#ifndef DATE_UNIX_TIMESTAMP_TO_DATE_H
#define DATE_UNIX_TIMESTAMP_TO_DATE_H

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
 * Converts UNIX timestamp to time_t.
 *
 * @param ts The timestamp value.
 * @param unit Unit: 's' for seconds, 'm' for milliseconds.
 * @return time_t timestamp, or -1 on invalid unit.
 */
EVERYUTIL_API time_t unix_timestamp_to_date(long long ts, char unit);

#ifdef __cplusplus
}
#endif

#endif // DATE_UNIX_TIMESTAMP_TO_DATE_H