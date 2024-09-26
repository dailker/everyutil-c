#include <stdio.h>
#include <time.h>
#include "date/end_of_month.h"

int main(void) {
    time_t mid_month = 946771200; // Jan 2, 2000
    time_t result = end_of_month(mid_month);
    
    struct tm *tm_result = localtime(&result);
    printf("End of month test: %s\n", 
           (tm_result && tm_result->tm_mday == 31 && tm_result->tm_mon == 0) ? "PASSED" : "FAILED");
    return 0;
}