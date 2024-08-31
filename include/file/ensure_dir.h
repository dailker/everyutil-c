#ifndef FILE_ENSURE_DIR_H
#define FILE_ENSURE_DIR_H

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
 * Creates a directory and any missing parent directories.
 *
 * @param path Directory path.
 * @return 0 on success, -1 on failure.
 */
EVERYUTIL_API int ensure_dir(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILE_ENSURE_DIR_H