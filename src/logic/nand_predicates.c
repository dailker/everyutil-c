#include "logic/nand_predicates.h"

EVERYUTIL_API int nand_predicates(int value, predicate_func pred1, predicate_func pred2) { return !(pred1(value) && pred2(value)); }