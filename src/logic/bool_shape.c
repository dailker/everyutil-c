#include "logic/bool_shape.h"

EVERYUTIL_API int bool_shape(const int* values, size_t size, const int* shape, size_t shape_size) { for (size_t i = 0; i < size && i < shape_size; i++) if (values[i] != shape[i]) return 0; return 1; }