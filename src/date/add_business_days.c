#include "date/add_business_days.h"

EVERYUTIL_API time_t add_business_days(time_t timestamp, int days) {
    time_t result = timestamp;
    while (days > 0) {
        result += 86400; // Add one day
        struct tm *tm_info = localtime(&result);
        if (tm_info && tm_info->tm_wday != 0 && tm_info->tm_wday != 6) {
            days--;
        }
    }
    return result;
}