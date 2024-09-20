#include "logic/implies.h"

EVERYUTIL_API int implies(int a, int b) {
    return !a || b;
}