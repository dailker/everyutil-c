#ifndef LOGIC_BOOL_BY_PROBABILITY_H
#define LOGIC_BOOL_BY_PROBABILITY_H

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
 * Returns true based on probability.
 *
 * @param probability Probability (0.0 to 1.0).
 * @return Random boolean based on probability.
 */
EVERYUTIL_API int bool_by_probability(double probability);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOL_BY_PROBABILITY_H