#include "logic/create_debounced_boolean.h"

static int last_val = 0;
static int count = 0;

EVERYUTIL_API int create_debounced_boolean(int input, int threshold) {
    if (input == last_val) count++;
    else count = 0;
    last_val = input;
    return count >= threshold ? input : 0;
}