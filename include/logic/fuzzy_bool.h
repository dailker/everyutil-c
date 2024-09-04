#ifndef LOGIC_FUZZY_BOOL_H
#define LOGIC_FUZZY_BOOL_H

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
 * Converts confidence score to boolean with threshold.
 *
 * @param value Confidence value (0.0 to 1.0).
 * @param threshold Threshold for conversion.
 * @return Boolean result.
 */
EVERYUTIL_API int fuzzy_bool(double value, double threshold);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_FUZZY_BOOL_H