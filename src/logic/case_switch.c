#include "logic/case_switch.h"

EVERYUTIL_API int case_switch(int input, const case_pair* cases, size_t count, int default_value) {
    if (!cases) return default_value;
    
    for (size_t i = 0; i < count; i++) {
        if (cases[i].key == input) return cases[i].value;
    }
    
    return default_value;
}