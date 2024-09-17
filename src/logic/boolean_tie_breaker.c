#include "logic/boolean_tie_breaker.h"

EVERYUTIL_API int boolean_tie_breaker(int primary, int secondary, int backup) {
    int p = !!primary;
    int s = !!secondary;
    
    if (p == s) {
        return !!backup;
    } else {
        return p ? p : s;
    }
}