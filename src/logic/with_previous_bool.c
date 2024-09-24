#include "logic/with_previous_bool.h"
#include <stdlib.h>

static int previous = 0;

EVERYUTIL_API int with_previous_bool(int current) {
    int result = current && previous;
    previous = current;
    return result;
}