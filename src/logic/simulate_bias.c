#include "logic/simulate_bias.h"
#include <stdlib.h>

EVERYUTIL_API int simulate_bias(double probability) { return (rand() / (double)RAND_MAX) < probability; }