#include "logic/is_boolean_like.h"
#include <string.h>

EVERYUTIL_API int is_boolean_like(const char* str) {
    if (!str) return 0;
    
    return strcmp(str, "true") == 0 || 
           strcmp(str, "false") == 0 || 
           strcmp(str, "0") == 0 || 
           strcmp(str, "1") == 0;
}