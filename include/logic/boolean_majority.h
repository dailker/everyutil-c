#ifndef LOGIC_BOOLEAN_MAJORITY_H
#define LOGIC_BOOLEAN_MAJORITY_H

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
 * Returns true if majority of flags are true.
 *
 * @param flags Array of boolean flags.
 * @param size Size of array.
 * @return 1 if majority true, 0 otherwise.
 */
EVERYUTIL_API int boolean_majority(const int* flags, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOLEAN_MAJORITY_H