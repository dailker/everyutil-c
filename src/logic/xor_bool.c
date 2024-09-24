#include "logic/xor_bool.h"

EVERYUTIL_API int xor_bool(int a, int b) {
    return (a && !b) || (!a && b);
}