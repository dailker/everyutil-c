#include "date/start_of_month.h"

EVERYUTIL_API time_t start_of_month(time_t timestamp) {
    struct tm *tm_info = localtime(&timestamp);
    if (!tm_info) return -1;
    tm_info->tm_mday = 1;
    tm_info->tm_hour = 0;
    tm_info->tm_min = 0;
    tm_info->tm_sec = 0;
    return mktime(tm_info);
}