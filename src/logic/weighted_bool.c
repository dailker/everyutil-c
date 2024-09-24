#include "logic/weighted_bool.h"

EVERYUTIL_API int weighted_bool(double weight, double threshold) {
    return weight >= threshold;
}