#ifndef ARRAY_ARRAY_MACHINE_H
#define ARRAY_ARRAY_MACHINE_H

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

/**
 * Instruction for array machine operation.
 */
typedef enum {
    ARRAY_OP_SWAP,
    ARRAY_OP_ADD,
    ARRAY_OP_SET
} ArrayOpType;

typedef struct {
    ArrayOpType op;
    size_t i;
    size_t j;      // only used for 'swap'
    double value;  // used for 'add' and 'set'
} ArrayInstruction;

/**
 * Executes a list of instructions on a copy of the input array.
 *
 * @param array Input array of doubles.
 * @param length Length of the array.
 * @param instructions Array of ArrayInstruction structs.
 * @param num_instructions Number of instructions.
 * @return New array after processing. NULL on failure. Caller must free.
 */
EVERYUTIL_API double* array_machine(
    const double* array,
    size_t length,
    const ArrayInstruction* instructions,
    size_t num_instructions
);

#ifdef __cplusplus
}
#endif

#endif // ARRAY_ARRAY_MACHINE_H
