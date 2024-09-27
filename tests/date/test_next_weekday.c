#include <stdio.h>
#include <time.h>
#include "date/next_weekday.h"

int main(void) {
    time_t saturday = 946684800; // Jan 1, 2000 (Saturday)
    time_t next_monday = next_weekday(saturday, 1); // Next Monday
    
    struct tm *tm_result = localtime(&next_monday);
    printf("Next Monday test: %s\n", 
           (tm_result && tm_result->tm_wday == 1) ? "PASSED" : "FAILED");
    
    return 0;
}