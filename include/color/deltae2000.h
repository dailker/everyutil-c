#ifndef COLOR_DELTAE2000_H
#define COLOR_DELTAE2000_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef EVERYUTIL_BUILD
    #define EVERYUTIL_API __declspec(dllexport)
  #else
    #define EVERYUTIL_API __declspec(dllimport)
  #endif
#else
  #define EVERYUTIL_API
#endif

typedef struct {
    double l;
    double a;
    double b;
} LAB;

/**
 * Calculates the Delta E 2000 color difference between two LAB colors.
 *
 * @param lab1 First LAB color.
 * @param lab2 Second LAB color.
 * @return Delta E 2000 difference.
 */
EVERYUTIL_API double deltaE2000(LAB lab1, LAB lab2);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_DELTAE2000_H */
