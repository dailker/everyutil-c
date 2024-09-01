#ifndef LOGIC_BOOLEAN_BY_ENTROPY_H
#define LOGIC_BOOLEAN_BY_ENTROPY_H

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
 * Returns true based on entropy level (noise scale).
 *
 * @param entropy Entropy level (0.0 to 1.0).
 * @return Random boolean based on entropy.
 */
EVERYUTIL_API int boolean_by_entropy(double entropy);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOLEAN_BY_ENTROPY_H