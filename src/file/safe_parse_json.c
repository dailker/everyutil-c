#include "file/safe_parse_json.h"
#include <string.h>

EVERYUTIL_API int safe_parse_json(const char* json) {
    if (!json) return 0;
    
    // Basic JSON validation - check for balanced braces/brackets
    int braces = 0, brackets = 0;
    int in_string = 0, escaped = 0;
    
    for (const char *p = json; *p; p++) {
        if (escaped) {
            escaped = 0;
            continue;
        }
        
        if (*p == '\\') {
            escaped = 1;
            continue;
        }
        
        if (*p == '"') {
            in_string = !in_string;
            continue;
        }
        
        if (in_string) continue;
        
        if (*p == '{') braces++;
        else if (*p == '}') braces--;
        else if (*p == '[') brackets++;
        else if (*p == ']') brackets--;
    }
    
    return braces == 0 && brackets == 0 && !in_string;
}