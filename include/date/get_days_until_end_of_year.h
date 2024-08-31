#ifndef DATE_GET_DAYS_UNTIL_END_OF_YEAR_H
#define DATE_GET_DAYS_UNTIL_END_OF_YEAR_H

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
 * Returns days left until December 31.
 *
 * @param timestamp Input timestamp.
 * @return Days until end of year.
 */
EVERYUTIL_API int get_days_until_end_of_year(time_t timestamp);

#ifdef __cplusplus
}
#endif

#endif // DATE_GET_DAYS_UNTIL_END_OF_YEAR_H