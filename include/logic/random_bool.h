#ifndef LOGIC_RANDOM_BOOL_H
#define LOGIC_RANDOM_BOOL_H

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
 * Returns true with specified probability.
 *
 * @param probability Probability (0.0 to 1.0).
 * @return Random boolean (0 or 1).
 */
EVERYUTIL_API int random_bool(double probability);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_RANDOM_BOOL_H