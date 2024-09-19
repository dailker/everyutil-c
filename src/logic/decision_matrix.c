#include "logic/decision_matrix.h"

EVERYUTIL_API int decision_matrix(int row, int col, const int* matrix, int rows, int cols) { if (row >= 0 && row < rows && col >= 0 && col < cols) return matrix[row * cols + col]; return 0; }