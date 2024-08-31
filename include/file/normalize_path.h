#ifndef FILE_NORMALIZE_PATH_H
#define FILE_NORMALIZE_PATH_H

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
 * Normalizes a file path by removing redundant separators.
 *
 * @param path Input path.
 * @return Dynamically allocated normalized path. Caller must free.
 */
EVERYUTIL_API char* normalize_path(const char* path);

#ifdef __cplusplus
}
#endif

#endif // FILE_NORMALIZE_PATH_H