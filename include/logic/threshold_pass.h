#ifndef LOGIC_THRESHOLD_PASS_H
#define LOGIC_THRESHOLD_PASS_H

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

#include <stddef.h>

/**
 * Returns true if at least min conditions are true.
 *
 * @param min Minimum number of true conditions required.
 * @param values Array of boolean values.
 * @param size Size of array.
 * @return 1 if threshold passed, 0 otherwise.
 */
EVERYUTIL_API int threshold_pass(int min, const int* values, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_THRESHOLD_PASS_H