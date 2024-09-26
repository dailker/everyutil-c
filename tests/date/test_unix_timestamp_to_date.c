#include <stdio.h>
#include "date/unix_timestamp_to_date.h"

int main(void) {
    time_t result_s = unix_timestamp_to_date(946684800LL, 's');
    printf("Seconds conversion: %s\n", result_s == 946684800 ? "PASSED" : "FAILED");
    
    time_t result_ms = unix_timestamp_to_date(946684800000LL, 'm');
    printf("Milliseconds conversion: %s\n", result_ms == 946684800 ? "PASSED" : "FAILED");
    
    time_t result_invalid = unix_timestamp_to_date(946684800LL, 'x');
    printf("Invalid unit: %s\n", result_invalid == -1 ? "PASSED" : "FAILED");
    
    return 0;
}