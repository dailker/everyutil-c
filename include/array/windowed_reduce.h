#ifndef ARRAY_WINDOWED_REDUCE_H
#define ARRAY_WINDOWED_REDUCE_H

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
 * Type of reducer callback used by windowedReduce.
 * 
 * @param acc Pointer to the accumulator value.
 * @param window Pointer to array of pointers representing the current window.
 * @param windowSize Number of elements in the window.
 * @param index Current start index of the window in the array.
 * @param array Pointer to the entire input array.
 * @param arrayLength Length of the input array.
 * @return Pointer to updated accumulator (may be the same as input acc).
 */
typedef void* (*windowed_reduce_callback)(
    void* acc,
    void** window,
    size_t windowSize,
    size_t index,
    void** array,
    size_t arrayLength
);

/**
 * Applies a reducer function on sliding windows of the array.
 * 
 * @param array Pointer to an array of pointers (generic elements).
 * @param arrayLength Length of the input array.
 * @param reducer Reducer callback function.
 * @param initialValue Pointer to initial accumulator value.
 * @param windowSize Size of the sliding window.
 * @return Pointer to the final accumulator value, or NULL on failure.
 * 
 * @note The reducer function is responsible for managing the accumulator data.
 */
EVERYUTIL_API void* windowedReduce(
    void** array,
    size_t arrayLength,
    windowed_reduce_callback reducer,
    void* initialValue,
    size_t windowSize
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_WINDOWED_REDUCE_H
