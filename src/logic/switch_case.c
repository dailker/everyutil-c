#include "logic/switch_case.h"

EVERYUTIL_API int switch_case(int input, const int* cases, const int* values, size_t count, int default_val) { for (size_t i = 0; i < count; i++) { if (input == cases[i]) return values[i]; } return default_val; }