#ifndef FILE_LIST_FILES_H
#define FILE_LIST_FILES_H

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
 * Lists files in a directory.
 *
 * @param dir_path Directory path.
 * @param callback Function called for each file found.
 * @param user_data User data passed to callback.
 * @return 0 on success, -1 on error.
 */
EVERYUTIL_API int list_files(const char* dir_path, void (*callback)(const char* filename, void* user_data), void* user_data);

#ifdef __cplusplus
}
#endif

#endif // FILE_LIST_FILES_H