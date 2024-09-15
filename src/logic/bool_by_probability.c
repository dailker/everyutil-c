#include "logic/bool_by_probability.h"
#include <stdlib.h>

EVERYUTIL_API int bool_by_probability(double probability) {
    return ((double)rand() / RAND_MAX) < probability;
}