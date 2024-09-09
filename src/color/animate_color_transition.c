#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color/animate_color_transition.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

typedef struct {
    double r, g, b, a;
} Color;

typedef struct {
    Color start, end;
    int duration;
    color_callback callback;
} Context;

static void* run_animation(void* arg) {
    Context* ctx = (Context*)arg;
    char hex[8];
    for (int t = 0; t <= ctx->duration; t += 100) {
        double ratio = (double)t / ctx->duration;
        Color current = {
            ctx->start.r + (ctx->end.r - ctx->start.r) * ratio,
            ctx->start.g + (ctx->end.g - ctx->start.g) * ratio,
            ctx->start.b + (ctx->end.b - ctx->start.b) * ratio,
            ctx->start.a + (ctx->end.a - ctx->start.a) * ratio
        };
        snprintf(hex, sizeof(hex), "#%02X%02X%02X", 
                 (int)(current.r * 255), (int)(current.g * 255), (int)(current.b * 255));
        ctx->callback(hex);
#ifdef _WIN32
        Sleep(100); // 100ms per step
#else
        usleep(100000); // 100ms per step
#endif
    }
    free(ctx);
    return NULL;
}

EVERYUTIL_API void* animate_color_transition(const char* fromColor, const char* toColor, int duration, color_callback callback) {
    if (!fromColor || !toColor || duration <= 0 || !callback) return NULL;

    Context* ctx = malloc(sizeof(Context));
    if (!ctx) return NULL;

    // Simplified color parsing (assumes valid #RRGGBB hex)
    unsigned int r1, g1, b1, r2, g2, b2;
    if (sscanf(fromColor, "#%2x%2x%2x", &r1, &g1, &b1) != 3 ||
        sscanf(toColor, "#%2x%2x%2x", &r2, &g2, &b2) != 3) {
        free(ctx);
        return NULL;
    }

    ctx->start = (Color){r1 / 255.0, g1 / 255.0, b1 / 255.0, 1.0};
    ctx->end = (Color){r2 / 255.0, g2 / 255.0, b2 / 255.0, 1.0};
    ctx->duration = duration;
    ctx->callback = callback;

#ifdef _WIN32
    HANDLE thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)run_animation, ctx, 0, NULL);
    if (!thread) {
        free(ctx);
        return NULL;
    }
    return thread;
#else
    pthread_t thread;
    if (pthread_create(&thread, NULL, run_animation, ctx) != 0) {
        free(ctx);
        return NULL;
    }
    return (void*)thread;
#endif
}

EVERYUTIL_API void animate_color_transition_stop(void* handle) {
    if (!handle) return;
#ifdef _WIN32
    TerminateThread((HANDLE)handle, 0);
    CloseHandle((HANDLE)handle);
#else
    pthread_cancel((pthread_t)handle);
    pthread_join((pthread_t)handle, NULL);
#endif
}