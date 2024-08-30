#ifndef FILE_CREATE_TEMP_FILE_H
#define FILE_CREATE_TEMP_FILE_H

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
 * Creates a temporary file.
 *
 * @param prefix Optional prefix for filename.
 * @return Dynamically allocated path to temp file. Caller must free.
 */
EVERYUTIL_API char* create_temp_file(const char* prefix);

#ifdef __cplusplus
}
#endif

#endif // FILE_CREATE_TEMP_FILE_H