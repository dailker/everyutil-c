#include "color/get_brightness.h"
EVERYUTIL_API int get_brightness(unsigned char r, unsigned char g, unsigned char b) {
    return (int)((299 * r + 587 * g + 114 * b) / 1000);
}