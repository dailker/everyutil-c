#ifndef LOGIC_BOOLEAN_EDGE_DETECTOR_H
#define LOGIC_BOOLEAN_EDGE_DETECTOR_H

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

typedef struct {
    int rising;
    int falling;
} edge_result_t;

/**
 * Detects rising/falling edges between boolean values.
 *
 * @param input Current boolean value.
 * @param previous Previous boolean value.
 * @return Edge detection result.
 */
EVERYUTIL_API edge_result_t boolean_edge_detector(int input, int previous);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_BOOLEAN_EDGE_DETECTOR_H