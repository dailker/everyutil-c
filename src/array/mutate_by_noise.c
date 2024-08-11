#include "array/mutate_by_noise.h"
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

#include <math.h>

// Initialize random seed once
static int seeded = 0;
static void seed_random() {
    if (!seeded) {
        // Use time + pid for seed to reduce repetition
        unsigned int seed = (unsigned int)time(NULL);
#ifdef _WIN32
        seed ^= (unsigned int)GetCurrentProcessId();
#else
        seed ^= (unsigned int)getpid();
#endif
        srand(seed);
        seeded = 1;
    }
}

EVERYUTIL_API double* mutate_by_noise(const double* array, size_t length, double strength) {
    if (!array || length == 0) return NULL;
    if (strength < 0.0) strength = 0.1;

    seed_random();

    double* result = (double*)malloc(length * sizeof(double));
    if (!result) return NULL;

    for (size_t i = 0; i < length; ++i) {
        // rand() returns int in [0, RAND_MAX]
        double rand01 = ((double)rand()) / RAND_MAX; // [0,1]
        double noise = (rand01 * 2.0 - 1.0) * strength * array[i];
        result[i] = array[i] + noise;
    }

    return result;
}
