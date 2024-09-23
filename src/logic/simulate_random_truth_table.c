#include "logic/simulate_random_truth_table.h"
#include <stdlib.h>

EVERYUTIL_API int simulate_random_truth_table(int inputs) { return rand() % 2; }