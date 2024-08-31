#ifndef FILE_SANITIZE_FILENAME_H
#define FILE_SANITIZE_FILENAME_H

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
 * Sanitizes a filename by replacing illegal characters.
 *
 * @param filename Input filename.
 * @return Dynamically allocated sanitized filename. Caller must free.
 */
EVERYUTIL_API char* sanitize_filename(const char* filename);

#ifdef __cplusplus
}
#endif

#endif // FILE_SANITIZE_FILENAME_H