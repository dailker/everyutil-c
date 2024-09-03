#ifndef LOGIC_DECISION_MATRIX_H
#define LOGIC_DECISION_MATRIX_H

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
typedef int (*predicate_func)(int);
typedef int (*transform_func)(int);

EVERYUTIL_API int decision_matrix(int row, int col, const int* matrix, int rows, int cols);

#ifdef __cplusplus
}
#endif

#endif