#include "logic/create_decision_graph.h"

EVERYUTIL_API int create_decision_graph(int input, const int* nodes, size_t count) { return nodes[input % count]; }