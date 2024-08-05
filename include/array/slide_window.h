#ifndef ARRAY_SLIDE_WINDOW_H
#define ARRAY_SLIDE_WINDOW_H

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

/**
 * Sliding window result structure.
 * - windows: array of pointers, each pointing to a chunk of `size` elements.
 * - count: number of chunks/windows.
 */
typedef struct {
    void** windows;
    size_t count;
} slide_window_result_t;

/**
 * Creates sliding windows over the input array.
 * 
 * @param array Pointer to input array.
 * @param length Number of elements in array.
 * @param element_size Size of each element in bytes.
 * @param size Size of each sliding window.
 * @param step Step size between windows (default 1).
 * @return slide_window_result_t containing array of pointers to window chunks and count.
 *         Each chunk is dynamically allocated and must be freed.
 *         The `windows` array must also be freed by caller.
 *         On error, returns {NULL, 0}.
 */
EVERYUTIL_API slide_window_result_t slide_window(const void* array, size_t length, size_t element_size, size_t size, size_t step);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_SLIDE_WINDOW_H
