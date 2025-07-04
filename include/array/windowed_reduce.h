#ifndef ARRAY_WINDOWED_REDUCE_H
#define ARRAY_WINDOWED_REDUCE_H

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

#include <stddef.h>

/**
 * Function pointer type for the reducer function applied to each window.
 * @param acc Accumulator value.
 * @param window Array of pointers to elements in the current window.
 * @param window_size Number of elements in the window.
 * @param index Starting index of the window in the original array.
 * @param array The original input array.
 * @param array_length Length of the original array.
 * @return Updated accumulator value (caller retains ownership).
 */
typedef void* (*windowed_reducer_fn)(void* acc, void** window, size_t window_size, size_t index, void** array, size_t array_length);

/**
 * Applies a reducer function over sliding windows of the input array.
 * @param array Input array of pointers to elements.
 * @param length Number of elements in the array.
 * @param reducer Function to apply to each window.
 * @param initial_value Initial accumulator value.
 * @param window_size Size of the sliding window.
 * @return Final accumulator value after processing all windows.
 *         Returns NULL on error (e.g., invalid input or memory allocation failure).
 * Caller is responsible for freeing the returned value if dynamically allocated.
 */
EVERYUTIL_API void* windowedReduce(void** array, size_t length, windowed_reducer_fn reducer, void* initial_value, size_t window_size);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_WINDOWED_REDUCE_H