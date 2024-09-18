#include "logic/confidence_weighted_decision.h"

EVERYUTIL_API int confidence_weighted_decision(const double* confidences, const int* values, size_t count) { double max_conf = 0; int result = 0; for (size_t i = 0; i < count; i++) { if (confidences[i] > max_conf) { max_conf = confidences[i]; result = values[i]; } } return result; }