#include "logic/confidence_merge.h"

EVERYUTIL_API int confidence_merge(double conf1, double conf2) { return (conf1 + conf2) / 2.0 >= 0.5; }