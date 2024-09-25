#include <stdio.h>
#include <math.h>
#include "color/deltae2000.h"

int main(void) {
    LAB lab1, lab2;
    double delta;
    
    // Test identical colors
    lab1.l = 50.0; lab1.a = 0.0; lab1.b = 0.0;
    lab2.l = 50.0; lab2.a = 0.0; lab2.b = 0.0;
    delta = deltaE2000(lab1, lab2);
    if (fabs(delta) < 0.01) {
        printf("identical colors: PASSED\n");
    } else {
        printf("identical colors: FAILED (delta: %.3f)\n", delta);
    }
    
    // Test different colors
    lab1.l = 50.0; lab1.a = 2.6; lab1.b = -79.0;
    lab2.l = 50.0; lab2.a = 0.0; lab2.b = -82.7;
    delta = deltaE2000(lab1, lab2);
    if (delta > 0.0 && delta < 10.0) {
        printf("different colors: PASSED\n");
    } else {
        printf("different colors: FAILED (delta: %.3f)\n", delta);
    }
    
    // Test black vs white
    lab1.l = 0.0; lab1.a = 0.0; lab1.b = 0.0;
    lab2.l = 100.0; lab2.a = 0.0; lab2.b = 0.0;
    delta = deltaE2000(lab1, lab2);
    if (delta > 50.0) {
        printf("black vs white: PASSED\n");
    } else {
        printf("black vs white: FAILED (delta: %.3f)\n", delta);
    }
    
    return 0;
}