#include "file/copy_file.h"
#include <stdio.h>
#include <stdlib.h>

EVERYUTIL_API int copy_file(const char* src, const char* dest) {
    if (!src || !dest) return -1;
    
    FILE *source = fopen(src, "rb");
    if (!source) return -1;
    
    FILE *target = fopen(dest, "wb");
    if (!target) {
        fclose(source);
        return -1;
    }
    
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        if (fwrite(buffer, 1, bytes, target) != bytes) {
            fclose(source);
            fclose(target);
            return -1;
        }
    }
    
    fclose(source);
    fclose(target);
    return 0;
}