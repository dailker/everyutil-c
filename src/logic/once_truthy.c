#include "logic/once_truthy.h"

static int found = 0;

EVERYUTIL_API int once_truthy(int value) {
    if (!found && value) {
        found = 1;
        return 1;
    }
    return 0;
}