#include "file/sanitize_filename.h"
#include <stdlib.h>
#include <string.h>

EVERYUTIL_API char* sanitize_filename(const char* filename) {
    if (!filename) return NULL;
    
    size_t len = strlen(filename);
    char *result = malloc(len + 1);
    if (!result) return NULL;
    
    for (size_t i = 0; i <= len; i++) {
        char c = filename[i];
        if (c == '<' || c == '>' || c == ':' || c == '"' || c == '/' || 
            c == '\\' || c == '|' || c == '?' || c == '*') {
            result[i] = '_';
        } else {
            result[i] = c;
        }
    }
    
    return result;
}