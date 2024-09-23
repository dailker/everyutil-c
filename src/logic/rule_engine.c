#include "logic/rule_engine.h"
#include <stdlib.h>

EVERYUTIL_API int rule_engine(int input, const int* rules, const int* actions, size_t count) { for (size_t i = 0; i < count; i++) { if (input == rules[i]) return actions[i]; } return 0; }