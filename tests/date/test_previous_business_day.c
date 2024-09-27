#include <stdio.h>
#include <time.h>
#include "date/previous_business_day.h"

int main(void) {
    time_t monday = 946684800 + 2 * 86400; // Jan 3, 2000 (Monday)
    time_t result = previous_business_day(monday);
    
    struct tm *tm_result = localtime(&result);
    printf("Previous business day test: %s (day: %d)\n", 
           (tm_result && tm_result->tm_wday >= 1 && tm_result->tm_wday <= 5) ? "PASSED" : "FAILED",
           tm_result ? tm_result->tm_wday : -1);
    
    return 0;
}