#include "array/array_fingerprint.h"
#include <stdlib.h>
#include <stdio.h>

EVERYUTIL_API char* array_fingerprint(const double* array, size_t length) {
    if (!array && length > 0) return NULL;

    // Rough estimate for JSON string length: "[", commas, numbers as strings, "]", and '\0'
    size_t bufsize = length * 32 + length + 3;
    char* json = (char*)malloc(bufsize);
    if (!json) return NULL;

    size_t pos = 0;
    json[pos++] = '[';

    for (size_t i = 0; i < length; i++) {
        int written = snprintf(json + pos, bufsize - pos, "%.17g", array[i]);
        if (written < 0 || (size_t)written >= bufsize - pos) {
            free(json);
            return NULL;
        }
        pos += (size_t)written;

        if (i < length - 1) {
            if (pos + 1 >= bufsize) {
                free(json);
                return NULL;
            }
            json[pos++] = ',';
        }
    }

    if (pos + 2 >= bufsize) {
        free(json);
        return NULL;
    }

    json[pos++] = ']';
    json[pos] = '\0';

    unsigned int hash = 5381;
    for (size_t i = 0; i < pos; i++) {
        hash = ((hash << 5) + hash) + (unsigned char)json[i]; // hash * 33 + c
    }

    free(json);

    char* result = (char*)malloc(9); // 8 hex digits + null terminator
    if (!result) return NULL;

    snprintf(result, 9, "%08x", hash);
    return result;
}
