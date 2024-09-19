#include "logic/explain_predicate_run.h"

EVERYUTIL_API int explain_predicate_run(int value, predicate_func predicate) { return predicate(value); }