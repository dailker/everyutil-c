#include "date/next_weekday.h"

EVERYUTIL_API time_t next_weekday(time_t timestamp, int weekday) {
    struct tm *tm_info = localtime(&timestamp);
    if (!tm_info) return -1;
    
    int current_day = tm_info->tm_wday;
    int diff = (weekday + 7 - current_day) % 7;
    if (diff == 0) diff = 7; // Next occurrence, not today
    
    return timestamp + diff * 86400;
}