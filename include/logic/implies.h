#ifndef LOGIC_IMPLIES_H
#define LOGIC_IMPLIES_H

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
 * Logical implication (if A then B).
 *
 * @param a First boolean (antecedent).
 * @param b Second boolean (consequent).
 * @return Implication result (0 or 1).
 */
EVERYUTIL_API int implies(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_IMPLIES_H