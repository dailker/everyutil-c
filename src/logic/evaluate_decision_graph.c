#include "logic/evaluate_decision_graph.h"

EVERYUTIL_API int evaluate_decision_graph(int input, const int* graph, size_t size) { return graph[input % size]; }