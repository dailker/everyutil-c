#include "logic/biconditional.h"

EVERYUTIL_API int biconditional(int a, int b) {
    return !!a == !!b;
}