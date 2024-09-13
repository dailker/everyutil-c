#include "date/get_day_suffix.h"
#include <stdlib.h>
#include <stdio.h>

EVERYUTIL_API char* get_day_suffix(int day) {
    char *result = malloc(8);
    if (!result) return NULL;
    
    const char *suffix;
    if (day >= 11 && day <= 13) {
        suffix = "th";
    } else {
        switch (day % 10) {
            case 1: suffix = "st"; break;
            case 2: suffix = "nd"; break;
            case 3: suffix = "rd"; break;
            default: suffix = "th"; break;
        }
    }
    
    snprintf(result, 8, "%d%s", day, suffix);
    return result;
}