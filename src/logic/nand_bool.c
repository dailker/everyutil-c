#include "logic/nand_bool.h"

EVERYUTIL_API int nand_bool(int a, int b) {
    return !(a && b);
}