#include <stdio.h>
#include <time.h>
#include "date/start_of_month.h"

int main(void) {
    time_t mid_month = 946771200; // Jan 2, 2000 00:00:00
    time_t result = start_of_month(mid_month);
    
    struct tm *tm_result = localtime(&result);
    printf("Start of month test: %s\n", 
           (tm_result && tm_result->tm_mday == 1 && tm_result->tm_mon == 0) ? "PASSED" : "FAILED");
    return 0;
}