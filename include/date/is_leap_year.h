#ifndef DATE_IS_LEAP_YEAR_H
#define DATE_IS_LEAP_YEAR_H

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

/**
 * Checks if a year is a leap year.
 *
 * @param year The year to check.
 * @return 1 if leap year, 0 otherwise.
 */
EVERYUTIL_API int is_leap_year(int year);

#ifdef __cplusplus
}
#endif

#endif // DATE_IS_LEAP_YEAR_H