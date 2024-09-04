#ifndef LOGIC_FUZZY_LOGIC_GATE_H
#define LOGIC_FUZZY_LOGIC_GATE_H

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

typedef enum {
    FUZZY_AND,
    FUZZY_OR,
    FUZZY_NOT
} fuzzy_gate_type_t;

/**
 * Apply fuzzy logic operators to normalized values.
 *
 * @param type Gate type (AND, OR, NOT).
 * @param values Array of normalized values (0.0 to 1.0).
 * @param size Size of array.
 * @return Fuzzy logic result.
 */
EVERYUTIL_API double fuzzy_logic_gate(fuzzy_gate_type_t type, const double* values, size_t size);

#ifdef __cplusplus
}
#endif

#endif // LOGIC_FUZZY_LOGIC_GATE_H