#ifndef LOGIC_EVALUATE_DECISION_GRAPH_H
#define LOGIC_EVALUATE_DECISION_GRAPH_H

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
typedef int (*predicate_func)(int);
typedef int (*transform_func)(int);

EVERYUTIL_API int evaluate_decision_graph(int input, const int* graph, size_t size);

#ifdef __cplusplus
}
#endif

#endif