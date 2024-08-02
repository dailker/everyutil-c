#ifndef ARRAY_AUTO_DESCRIBE_H
#define ARRAY_AUTO_DESCRIBE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef BUILDING_EVERYUTIL
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/** Enum for array element types */
typedef enum {
    ARRAY_TYPE_NUMBER,
    ARRAY_TYPE_STRING,
} ArrayType;

/**
 * Returns a human-readable summary of an array of numbers or strings.
 * 
 * @param array Pointer to array elements (double* for numbers, char** for strings).
 * @param length Number of elements.
 * @param type Type of elements (number or string).
 * @return Dynamically allocated description string (caller must free), or NULL on failure.
 */
EVERYUTIL_API char* auto_describe(const void* array, size_t length, ArrayType type);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_AUTO_DESCRIBE_H
