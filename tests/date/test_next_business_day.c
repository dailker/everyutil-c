#include <stdio.h>
#include <time.h>
#include "date/next_business_day.h"

int main(void) {
    time_t friday = 946684800 + 5 * 86400; // Jan 6, 2000 (Thursday)
    time_t result = next_business_day(friday);
    
    struct tm *tm_result = localtime(&result);
    printf("Next business day test: %s (day: %d)\n", 
           (tm_result && tm_result->tm_wday >= 1 && tm_result->tm_wday <= 5) ? "PASSED" : "FAILED",
           tm_result ? tm_result->tm_wday : -1);
    
    return 0;
}