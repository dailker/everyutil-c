#include "logic/logic_switch.h"

EVERYUTIL_API int logic_switch(int condition, int true_val, int false_val) { return condition ? true_val : false_val; }