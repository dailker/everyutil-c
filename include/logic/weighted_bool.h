#ifndef LOGIC_WEIGHTED_BOOL_H
#define LOGIC_WEIGHTED_BOOL_H

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
 * Maps a weight into a boolean with threshold cutoff.
 *
 * @param weight Weight value.
 * @param threshold Threshold for conversion (default 0.5).
 * @return Boolean result.
 */
EVERYUTIL_API int weighted_bool(double weight, double threshold);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_WEIGHTED_BOOL_H