#include "logic/bool_trend.h"

EVERYUTIL_API int bool_trend(const int* values, size_t size) { if (size < 2) return 0; int trend = 0; for (size_t i = 1; i < size; i++) { if (values[i] > values[i-1]) trend++; else if (values[i] < values[i-1]) trend--; } return trend > 0 ? 1 : (trend < 0 ? -1 : 0); }