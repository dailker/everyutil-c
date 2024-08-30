#ifndef DATE_IS_WEEKEND_H
#define DATE_IS_WEEKEND_H

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
 * Checks if a date falls on a weekend.
 *
 * @param timestamp The time_t timestamp to check.
 * @return 1 if weekend, 0 otherwise.
 */
EVERYUTIL_API int is_weekend(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_IS_WEEKEND_H