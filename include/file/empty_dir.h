#ifndef FILE_EMPTY_DIR_H
#define FILE_EMPTY_DIR_H

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
 * Empties directory contents but keeps the directory.
 *
 * @param path Directory path.
 * @return 0 on success, -1 on error.
 */
EVERYUTIL_API int empty_dir(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILE_EMPTY_DIR_H