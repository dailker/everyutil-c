#include "logic/run_if.h"

EVERYUTIL_API void run_if(int condition, void (*action)(void)) { if (condition && action) action(); }