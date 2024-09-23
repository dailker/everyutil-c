#include "logic/ternary_logic_table.h"

EVERYUTIL_API ternary_result_t ternary_logic_table(int truthy, int falsy, int unknown) {
    if (unknown) return TERNARY_UNKNOWN;
    if (truthy) return TERNARY_TRUE;
    if (falsy) return TERNARY_FALSE;
    return TERNARY_INDETERMINATE;
}