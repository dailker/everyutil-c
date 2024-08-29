#ifndef DATE_DAYS_IN_MONTH_H
#define DATE_DAYS_IN_MONTH_H

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
 * Gets the number of days in a given month and year.
 *
 * @param year The year.
 * @param month The month (0=Jan, 11=Dec).
 * @return Number of days in the month.
 */
EVERYUTIL_API int days_in_month(int year, int month);

#ifdef __cplusplus
}
#endif

#endif // DATE_DAYS_IN_MONTH_H