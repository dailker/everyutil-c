#ifndef FILE_GET_DIRECTORY_SIZE_H
#define FILE_GET_DIRECTORY_SIZE_H

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
 * Calculates total size of directory recursively.
 *
 * @param path Directory path.
 * @return Total size in bytes, -1 on error.
 */
EVERYUTIL_API long get_directory_size(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILE_GET_DIRECTORY_SIZE_H