#ifndef DATE_DATE_TO_UNIX_TIMESTAMP_H
#define DATE_DATE_TO_UNIX_TIMESTAMP_H

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
 * Converts a time_t timestamp to UNIX timestamp in seconds or milliseconds.
 *
 * @param timestamp The time_t timestamp to convert.
 * @param unit Unit for output: 's' for seconds, 'm' for milliseconds.
 * @return UNIX timestamp as long long. Returns -1 on invalid unit.
 */
EVERYUTIL_API long long date_to_unix_timestamp(time_t timestamp, char unit);

#ifdef __cplusplus
}
#endif

#endif // DATE_DATE_TO_UNIX_TIMESTAMP_H