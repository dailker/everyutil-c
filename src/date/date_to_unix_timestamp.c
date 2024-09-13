#include "date/date_to_unix_timestamp.h"

EVERYUTIL_API long long date_to_unix_timestamp(time_t timestamp, char unit) {
    if (unit == 's') {
        return (long long)timestamp;
    } else if (unit == 'm') {
        return (long long)timestamp * 1000LL;
    }
    return -1; // Invalid unit
}