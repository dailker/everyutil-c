#include "logic/fuzzy_bool.h"

EVERYUTIL_API int fuzzy_bool(double value, double threshold) {
    return value >= threshold ? 1 : 0;
}