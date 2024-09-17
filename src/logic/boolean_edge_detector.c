#include "logic/boolean_edge_detector.h"

EVERYUTIL_API edge_result_t boolean_edge_detector(int input, int previous) {
    edge_result_t result;
    result.rising = !previous && input;
    result.falling = previous && !input;
    return result;
}