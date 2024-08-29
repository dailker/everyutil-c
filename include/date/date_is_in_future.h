#ifndef DATE_DATE_IS_IN_FUTURE_H
#define DATE_DATE_IS_IN_FUTURE_H

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
 * Checks if a date is in the future relative to now.
 *
 * @param timestamp The time_t timestamp to check.
 * @return 1 if in future, 0 otherwise.
 */
EVERYUTIL_API int date_is_in_future(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_DATE_IS_IN_FUTURE_H