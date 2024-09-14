#include "date/end_of_month.h"

EVERYUTIL_API time_t end_of_month(time_t timestamp) {
    struct tm *tm_info = localtime(&timestamp);
    if (!tm_info) return -1;
    tm_info->tm_mon++;
    tm_info->tm_mday = 0;
    tm_info->tm_hour = 23;
    tm_info->tm_min = 59;
    tm_info->tm_sec = 59;
    return mktime(tm_info);
}