#ifndef ARRAY_DETECT_PATTERN_H
#define ARRAY_DETECT_PATTERN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

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
 * Result of detectPattern.
 */
typedef struct {
    int* pattern;      ///< Dynamically allocated pattern array.
    size_t pattern_len;///< Length of the pattern.
    size_t repeats;    ///< Number of times the pattern repeats.
} PatternResult;

/**
 * Detects repeating sequences in an int array.
 * Returns a PatternResult with pattern (must be freed) and repeats count,
 * or {NULL, 0, 0} if no pattern is found.
 * 
 * @param array Input array of ints.
 * @param length Length of the input array.
 * @return PatternResult with pattern and repeats or all zero/NULL if none.
 */
EVERYUTIL_API PatternResult detect_pattern(const int* array, size_t length);

/**
 * Frees memory allocated by detect_pattern.
 * @param result PatternResult to free.
 */
EVERYUTIL_API void free_pattern_result(PatternResult result);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_DETECT_PATTERN_H
