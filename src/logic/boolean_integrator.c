#include "logic/boolean_integrator.h"
#include <stdlib.h>

static int sum = 0;

EVERYUTIL_API int boolean_integrator(int input, int reset) {
    if (reset) sum = 0;
    sum += input;
    return sum;
}