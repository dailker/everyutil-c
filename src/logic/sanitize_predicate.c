#include "logic/sanitize_predicate.h"

EVERYUTIL_API int sanitize_predicate(int value) { return value < 0 ? 0 : (value > 1 ? 1 : value); }