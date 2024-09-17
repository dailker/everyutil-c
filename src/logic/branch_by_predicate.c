#include "logic/branch_by_predicate.h"

EVERYUTIL_API int branch_by_predicate(int value, predicate_func predicate, int true_val, int false_val) { return predicate(value) ? true_val : false_val; }