#ifndef FILE_SAFE_PARSE_JSON_H
#define FILE_SAFE_PARSE_JSON_H

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
 * Safely parses JSON string (basic validation only).
 *
 * @param json JSON string to validate.
 * @return 1 if valid JSON format, 0 otherwise.
 */
EVERYUTIL_API int safe_parse_json(const char* json);

#ifdef __cplusplus
}
#endif

#endif // FILE_SAFE_PARSE_JSON_H