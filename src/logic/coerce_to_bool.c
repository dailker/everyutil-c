#include "logic/coerce_to_bool.h"
#include <string.h>
#include <ctype.h>

static void to_lower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower(str[i]);
    }
}

EVERYUTIL_API int coerce_to_bool(const char* str, int strict) {
    if (!str) return 0;
    
    char buffer[32];
    strncpy(buffer, str, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    to_lower(buffer);
    
    if (strict) {
        return strcmp(buffer, "true") == 0 || 
               strcmp(buffer, "1") == 0 || 
               strcmp(buffer, "yes") == 0;
    } else {
        return !(strcmp(buffer, "") == 0 || 
                 strcmp(buffer, "0") == 0 || 
                 strcmp(buffer, "false") == 0 || 
                 strcmp(buffer, "no") == 0 || 
                 strcmp(buffer, "null") == 0 || 
                 strcmp(buffer, "undefined") == 0);
    }
}