#include "logic/branch.h"

EVERYUTIL_API int branch(int condition, int true_val, int false_val) { return condition ? true_val : false_val; }