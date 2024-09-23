#include "logic/toggle_on_condition.h"

static int toggle_state = 0;

EVERYUTIL_API int toggle_on_condition(int condition) {
    if (condition) toggle_state = !toggle_state;
    return toggle_state;
}