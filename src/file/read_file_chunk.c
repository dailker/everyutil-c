#include "file/read_file_chunk.h"
#include <stdio.h>

EVERYUTIL_API int read_file_chunk(const char* path, long start, size_t length, void* buffer) {
    if (!path || !buffer) return -1;
    
    FILE *file = fopen(path, "rb");
    if (!file) return -1;
    
    if (fseek(file, start, SEEK_SET) != 0) {
        fclose(file);
        return -1;
    }
    
    size_t bytes_read = fread(buffer, 1, length, file);
    fclose(file);
    
    return (int)bytes_read;
}