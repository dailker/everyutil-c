#ifndef LOGIC_SIMULATE_COIN_FLIPS_H
#define LOGIC_SIMULATE_COIN_FLIPS_H

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
 * Fills array with random boolean values (coin flips).
 *
 * @param array Array to fill with random booleans.
 * @param size Size of array.
 */
EVERYUTIL_API void simulate_coin_flips(int* array, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_SIMULATE_COIN_FLIPS_H