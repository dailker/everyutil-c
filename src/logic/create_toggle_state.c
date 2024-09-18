#include "logic/create_toggle_state.h"
#include <stdlib.h>

static int toggle = 0;

EVERYUTIL_API int create_toggle_state(int trigger) {
    if (trigger) toggle = !toggle;
    return toggle;
}