#ifndef FILE_COMPARE_FILES_H
#define FILE_COMPARE_FILES_H

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
 * Compares two files for binary equality.
 *
 * @param pathA First file path.
 * @param pathB Second file path.
 * @return 1 if files are equal, 0 if different, -1 on error.
 */
EVERYUTIL_API int compare_files(const char* pathA, const char* pathB);

#ifdef __cplusplus
}
#endif

#endif // FILE_COMPARE_FILES_H