#include "date/unix_timestamp_to_date.h"

EVERYUTIL_API time_t unix_timestamp_to_date(long long ts, char unit) {
    if (unit == 's') {
        return (time_t)ts;
    } else if (unit == 'm') {
        return (time_t)(ts / 1000LL);
    }
    return -1;
}