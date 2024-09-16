#include "logic/boolean_by_entropy.h"
#include <stdlib.h>

EVERYUTIL_API int boolean_by_entropy(double entropy) {
    return ((double)rand() / RAND_MAX) < entropy;
}