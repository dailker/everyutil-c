#ifndef LOGIC_TERNARY_LOGIC_TABLE_H
#define LOGIC_TERNARY_LOGIC_TABLE_H

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

typedef enum {
    TERNARY_TRUE,
    TERNARY_FALSE,
    TERNARY_UNKNOWN,
    TERNARY_INDETERMINATE
} ternary_result_t;

/**
 * Evaluates 3-valued logic combinations.
 *
 * @param truthy True condition.
 * @param falsy False condition.
 * @param unknown Unknown condition.
 * @return Ternary logic result.
 */
EVERYUTIL_API ternary_result_t ternary_logic_table(int truthy, int falsy, int unknown);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_TERNARY_LOGIC_TABLE_H