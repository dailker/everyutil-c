#ifndef FILE_READ_FILE_CHUNK_H
#define FILE_READ_FILE_CHUNK_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/**
 * Reads a chunk of bytes from a file.
 *
 * @param path File path.
 * @param start Start byte position.
 * @param length Number of bytes to read.
 * @param buffer Buffer to store data.
 * @return Number of bytes read, -1 on error.
 */
EVERYUTIL_API int read_file_chunk(const char* path, long start, size_t length, void* buffer);

#ifdef __cplusplus
}
#endif

#endif // FILE_READ_FILE_CHUNK_H