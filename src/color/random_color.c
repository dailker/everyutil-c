#include "color/random_color.h"
#include "color/rgb_to_hex.h"
#include <stdlib.h>
#include <time.h>

EVERYUTIL_API char* random_color(void) {
    static int seeded = 0;
    if (!seeded) {
        srand((unsigned int)time(NULL));
        seeded = 1;
    }

    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;

    return rgb_to_hex(r, g, b);
}