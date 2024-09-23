#include "logic/nor_bool.h"

EVERYUTIL_API int nor_bool(int a, int b) {
    return !(a || b);
}