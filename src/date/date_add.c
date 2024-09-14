#include "date/date_add.h"

EVERYUTIL_API time_t date_add(time_t timestamp, int days, int hours, int minutes, int seconds) {
    return timestamp + days * 86400 + hours * 3600 + minutes * 60 + seconds;
}