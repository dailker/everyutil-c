#include <stdio.h>
#include <time.h>

#include "date/date_to_unix_timestamp.h"

int main(void) {
    // Test with a known timestamp (January 1, 2000, 00:00:00 UTC)
    time_t test_time = 946684800; // Unix timestamp for 2000-01-01 00:00:00 UTC
    
    // Test seconds conversion
    long long result_s = date_to_unix_timestamp(test_time, 's');
    printf("Timestamp in seconds: ");
    if (result_s == 946684800LL) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 946684800, got %lld)\n", result_s);
    }
    
    // Test milliseconds conversion
    long long result_ms = date_to_unix_timestamp(test_time, 'm');
    printf("Timestamp in milliseconds: ");
    if (result_ms == 946684800000LL) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected 946684800000, got %lld)\n", result_ms);
    }
    
    // Test invalid unit
    long long result_invalid = date_to_unix_timestamp(test_time, 'x');
    printf("Invalid unit handling: ");
    if (result_invalid == -1) {
        printf("PASSED\n");
    } else {
        printf("FAILED (expected -1, got %lld)\n", result_invalid);
    }
    
    return 0;
}