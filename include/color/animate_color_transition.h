#ifndef ANIMATE_COLOR_TRANSITION_H
#define ANIMATE_COLOR_TRANSITION_H

#ifdef EVERYUTIL_BUILD
#define EVERYUTIL_API __declspec(dllexport)
#else
#define EVERYUTIL_API __declspec(dllimport)
#endif

typedef void (*color_callback)(const char* color);

EVERYUTIL_API void* animate_color_transition(const char* fromColor, const char* toColor, int duration, color_callback callback);
EVERYUTIL_API void animate_color_transition_stop(void* handle);

#endif