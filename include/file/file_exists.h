#ifndef FILE_FILE_EXISTS_H
#define FILE_FILE_EXISTS_H

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

/**
 * Checks if a file or directory exists.
 *
 * @param path File or directory path.
 * @return 1 if exists, 0 otherwise.
 */
EVERYUTIL_API int file_exists(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILE_FILE_EXISTS_H