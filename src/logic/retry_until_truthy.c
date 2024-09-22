#include "logic/retry_until_truthy.h"
#include <stdlib.h>

EVERYUTIL_API int retry_until_truthy(int (*fn)(void), int max_retries) { for (int i = 0; i < max_retries; i++) { if (fn()) return 1; } return 0; }