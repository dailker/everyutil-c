#include "date/is_same_day.h"

EVERYUTIL_API int is_same_day(time_t a, time_t b) {
    struct tm *tm_a = localtime(&a);
    if (!tm_a) return 0;
    struct tm tm_a_copy = *tm_a;
    
    struct tm *tm_b = localtime(&b);
    if (!tm_b) return 0;
    
    return tm_a_copy.tm_year == tm_b->tm_year && 
           tm_a_copy.tm_mon == tm_b->tm_mon && 
           tm_a_copy.tm_mday == tm_b->tm_mday;
}