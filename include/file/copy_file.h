#ifndef FILE_COPY_FILE_H
#define FILE_COPY_FILE_H

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
 * Copies a file from source to destination.
 *
 * @param src Source file path.
 * @param dest Destination file path.
 * @return 0 on success, -1 on failure.
 */
EVERYUTIL_API int copy_file(const char* src, const char* dest);

#ifdef __cplusplus
}
#endif

#endif // FILE_COPY_FILE_H