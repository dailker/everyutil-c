#include "array/array_machine.h"
#include <stdlib.h>

EVERYUTIL_API double* array_machine(
    const double* array,
    size_t length,
    const ArrayInstruction* instructions,
    size_t num_instructions
) {
    if (!array || !instructions || length == 0) return NULL;

    double* result = (double*)malloc(length * sizeof(double));
    if (!result) return NULL;

    for (size_t i = 0; i < length; ++i) {
        result[i] = array[i];
    }

    for (size_t k = 0; k < num_instructions; ++k) {
        ArrayInstruction ins = instructions[k];

        if (ins.i >= length) continue;
        if (ins.op == ARRAY_OP_SWAP && ins.j >= length) continue;

        switch (ins.op) {
            case ARRAY_OP_SWAP: {
                double tmp = result[ins.i];
                result[ins.i] = result[ins.j];
                result[ins.j] = tmp;
                break;
            }
            case ARRAY_OP_ADD:
                result[ins.i] += ins.value;
                break;
            case ARRAY_OP_SET:
                result[ins.i] = ins.value;
                break;
            default:
                // Unknown op — skip or handle
                break;
        }
    }

    return result;
}
