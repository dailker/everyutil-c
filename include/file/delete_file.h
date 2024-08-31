#ifndef FILE_DELETE_FILE_H
#define FILE_DELETE_FILE_H

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
 * Deletes a file or directory.
 *
 * @param path Path to file or directory.
 * @return 0 on success, -1 on failure.
 */
EVERYUTIL_API int delete_file(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILE_DELETE_FILE_H