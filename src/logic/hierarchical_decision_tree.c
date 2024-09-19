#include "logic/hierarchical_decision_tree.h"

EVERYUTIL_API int hierarchical_decision_tree(int input, const int* tree, size_t size) { return tree[input % size]; }