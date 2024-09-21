#include "logic/logic_pipe.h"

EVERYUTIL_API int logic_pipe(int input, transform_func* transforms, size_t count) { int result = input; for (size_t i = 0; i < count; i++) result = transforms[i](result); return result; }