#include "logic/boolean_memory.h"
#include <stdlib.h>

static int memory[10] = {0};
static int idx = 0;

EVERYUTIL_API int boolean_memory(int input) {
    memory[idx] = input;
    idx = (idx + 1) % 10;
    return memory[(idx + 9) % 10];
}