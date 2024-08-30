#ifndef DATE_GET_AGE_FROM_DOB_H
#define DATE_GET_AGE_FROM_DOB_H

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
 * Calculates age in years from birthdate.
 *
 * @param dob Date of birth timestamp.
 * @return Age in years.
 */
EVERYUTIL_API int get_age_from_dob(time_t dob);

#ifdef __cplusplus
}
#endif

#endif // DATE_GET_AGE_FROM_DOB_H