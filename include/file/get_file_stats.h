#ifndef FILE_GET_FILE_STATS_H
#define FILE_GET_FILE_STATS_H

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

#include <sys/stat.h>

/**
 * Gets file statistics.
 *
 * @param path File path.
 * @param stats Pointer to stat structure to fill.
 * @return 0 on success, -1 on failure.
 */
EVERYUTIL_API int get_file_stats(const char* path, struct stat* stats);

#ifdef __cplusplus
}
#endif

#endif // FILE_GET_FILE_STATS_H