#include <stdio.h>
#include <time.h>
#include "date/add_business_days.h"

int main(void) {
    time_t friday = 946684800 + 5 * 86400; // Jan 6, 2000 (Thursday)
    time_t result = add_business_days(friday, 1);
    
    struct tm *tm_result = localtime(&result);
    printf("Add 1 business day test: %s (day: %d)\n", 
           (tm_result && tm_result->tm_wday >= 1 && tm_result->tm_wday <= 5) ? "PASSED" : "FAILED",
           tm_result ? tm_result->tm_wday : -1);
    
    return 0;
}