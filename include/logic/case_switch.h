#ifndef LOGIC_CASE_SWITCH_H
#define LOGIC_CASE_SWITCH_H

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

typedef struct {
    int key;
    int value;
} case_pair;

EVERYUTIL_API int case_switch(int input, const case_pair* cases, size_t count, int default_value);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_CASE_SWITCH_H