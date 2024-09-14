#include "file/append_to_file.h"
#include <stdio.h>

EVERYUTIL_API int append_to_file(const char* path, const void* data, size_t size) {
    if (!path || !data) return -1;
    
    FILE *file = fopen(path, "ab");
    if (!file) return -1;
    
    size_t written = fwrite(data, 1, size, file);
    fclose(file);
    
    return written == size ? 0 : -1;
}