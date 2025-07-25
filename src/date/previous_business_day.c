#include "date/previous_business_day.h"

EVERYUTIL_API time_t previous_business_day(time_t timestamp) {
    time_t result = timestamp;
    do {
        result -= 86400; // Subtract one day
        struct tm *tm_info = localtime(&result);
        if (tm_info && tm_info->tm_wday != 0 && tm_info->tm_wday != 6) {
            break;
        }
    } while (1);
    return result;
}