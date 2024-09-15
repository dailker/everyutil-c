#include "logic/bias_boolean.h"
#include <stdlib.h>

EVERYUTIL_API int bias_boolean(int value, double bias) { return value || (rand() / (double)RAND_MAX < bias); }