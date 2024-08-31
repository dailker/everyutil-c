#ifndef FILE_SAFE_WRITE_FILE_H
#define FILE_SAFE_WRITE_FILE_H

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
 * Writes data to file atomically using temporary file.
 *
 * @param path Target file path.
 * @param data Data to write.
 * @param size Size of data.
 * @return 0 on success, -1 on failure.
 */
EVERYUTIL_API int safe_write_file(const char* path, const void* data, size_t size);

#ifdef __cplusplus
}
#endif

#endif // FILE_SAFE_WRITE_FILE_H