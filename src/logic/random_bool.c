#include "logic/random_bool.h"
#include <stdlib.h>

EVERYUTIL_API int random_bool(double probability) {
    if (probability <= 0.0) return 0;
    if (probability >= 1.0) return 1;
    return ((double)rand() / RAND_MAX) < probability;
}