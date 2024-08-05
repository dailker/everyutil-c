#ifndef ARRAY_RECONSTRUCT_SEQUENCE_H
#define ARRAY_RECONSTRUCT_SEQUENCE_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_WIN64)
  #ifdef EVERYUTIL_EXPORTS
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

#include <stddef.h>

/** Type tags for mixed-type array elements */
typedef enum {
    TYPE_NUMBER,
    TYPE_STRING,
    TYPE_OTHER
} rs_element_type_t;

/** Union representing one element */
typedef struct {
    rs_element_type_t type;
    union {
        double number;
        const char* string;
        void* other;
    } data;
} rs_element_t;

/**
 * Reconstructs a likely order of mixed-type array elements.
 *
 * @param input Array of elements to sort.
 * @param length Number of elements.
 * @return Newly allocated sorted array (caller must free), or NULL on failure.
 */
EVERYUTIL_API rs_element_t* reconstruct_sequence(const rs_element_t* input, size_t length);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_RECONSTRUCT_SEQUENCE_H
