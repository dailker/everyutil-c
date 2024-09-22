#include "logic/once.h"

static int called = 0;

EVERYUTIL_API int once(void (*fn)(void)) {
    if (!called && fn) {
        called = 1;
        fn();
        return 1;
    }
    return 0;
}