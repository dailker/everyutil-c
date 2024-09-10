#include "color/cycle_colors.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <pthread.h>
#endif

typedef struct {
    const char **colors;
    size_t colors_count;
    unsigned int interval_ms;
    color_apply_callback apply_callback;
    int running;
#ifdef _WIN32
    HANDLE thread;
#else
    pthread_t thread;
#endif
} color_cycle_t;

#ifdef _WIN32

static DWORD WINAPI cycle_thread(LPVOID arg) {
    color_cycle_t *cycle = (color_cycle_t *)arg;
    size_t i = 0;
    while (cycle->running) {
        cycle->apply_callback(cycle->colors[i % cycle->colors_count]);
        i++;
        Sleep(cycle->interval_ms);
    }
    return 0;
}

#else

static void *cycle_thread(void *arg) {
    color_cycle_t *cycle = (color_cycle_t *)arg;
    size_t i = 0;
    while (cycle->running) {
        cycle->apply_callback(cycle->colors[i % cycle->colors_count]);
        i++;
        usleep(cycle->interval_ms * 1000);
    }
    return NULL;
}

#endif

void *cycle_colors_start(const char **colors, size_t colors_count, unsigned int interval_ms, color_apply_callback apply_callback) {
    if (!colors || colors_count == 0 || !apply_callback) return NULL;

    color_cycle_t *cycle = malloc(sizeof(color_cycle_t));
    if (!cycle) return NULL;

    cycle->colors = colors;
    cycle->colors_count = colors_count;
    cycle->interval_ms = interval_ms;
    cycle->apply_callback = apply_callback;
    cycle->running = 1;

#ifdef _WIN32
    cycle->thread = CreateThread(NULL, 0, cycle_thread, cycle, 0, NULL);
    if (!cycle->thread) {
        free(cycle);
        return NULL;
    }
#else
    if (pthread_create(&cycle->thread, NULL, cycle_thread, cycle) != 0) {
        free(cycle);
        return NULL;
    }
#endif

    return cycle;
}

void cycle_colors_stop(void *cycle_handle) {
    if (!cycle_handle) return;
    color_cycle_t *cycle = (color_cycle_t *)cycle_handle;
    cycle->running = 0;

#ifdef _WIN32
    WaitForSingleObject(cycle->thread, INFINITE);
    CloseHandle(cycle->thread);
#else
    pthread_join(cycle->thread, NULL);
#endif

    free(cycle);
}