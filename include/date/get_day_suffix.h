#ifndef DATE_GET_DAY_SUFFIX_H
#define DATE_GET_DAY_SUFFIX_H

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
 * Adds "st", "nd", "rd", "th" to date number (1st, 2nd, 3rd, 4th).
 *
 * @param day Day number (1-31).
 * @return Dynamically allocated string with suffix. Caller must free.
 */
EVERYUTIL_API char* get_day_suffix(int day);

#ifdef __cplusplus
}
#endif

#endif // DATE_GET_DAY_SUFFIX_H