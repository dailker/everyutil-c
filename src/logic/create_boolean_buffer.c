#include "logic/create_boolean_buffer.h"

static int buffer[10] = {0};
static int idx = 0;

EVERYUTIL_API int create_boolean_buffer(int input) {
    buffer[idx] = input;
    idx = (idx + 1) % 10;
    return buffer[(idx + 9) % 10];
}