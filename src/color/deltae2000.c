#include <math.h>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "color/deltae2000.h"

static double deg2rad(double deg) {
    return deg * (M_PI / 180.0);
}

static double rad2deg(double rad) {
    return rad * (180.0 / M_PI);
}

static double _atan2_deg(double y, double x) {
    double theta = rad2deg(atan2(y, x));
    return (theta >= 0) ? theta : (theta + 360);
}

static double _cos_deg(double deg) {
    return cos(deg2rad(deg));
}



EVERYUTIL_API double deltaE2000(LAB lab1, LAB lab2) {
    // Step 1: Calculate C' for each color
    double L1 = lab1.l, a1 = lab1.a, b1 = lab1.b;
    double L2 = lab2.l, a2 = lab2.a, b2 = lab2.b;

    double C1 = sqrt(a1 * a1 + b1 * b1);
    double C2 = sqrt(a2 * a2 + b2 * b2);
    double C_bar = (C1 + C2) / 2.0;

    // Step 2: Calculate G
    double C_bar7 = pow(C_bar, 7);
    double G = 0.5 * (1 - sqrt(C_bar7 / (C_bar7 + pow(25.0, 7))));

    // Step 3: Calculate a'1 and a'2
    double a1_prime = a1 * (1 + G);
    double a2_prime = a2 * (1 + G);

    // Step 4: Calculate C'1 and C'2
    double C1_prime = sqrt(a1_prime * a1_prime + b1 * b1);
    double C2_prime = sqrt(a2_prime * a2_prime + b2 * b2);

    // Step 5: Calculate h'1 and h'2
    double h1_prime = (b1 == 0 && a1_prime == 0) ? 0 : _atan2_deg(b1, a1_prime);
    double h2_prime = (b2 == 0 && a2_prime == 0) ? 0 : _atan2_deg(b2, a2_prime);

    // Step 6: Calculate Delta L', Delta C', Delta H'
    double delta_L_prime = L2 - L1;
    double delta_C_prime = C2_prime - C1_prime;

    double h_diff = h2_prime - h1_prime;
    double delta_h_prime;

    if (C1_prime * C2_prime == 0)
        delta_h_prime = 0;
    else if (fabs(h_diff) <= 180)
        delta_h_prime = h_diff;
    else if (h_diff > 180)
        delta_h_prime = h_diff - 360;
    else
        delta_h_prime = h_diff + 360;

    double delta_H_prime = 2 * sqrt(C1_prime * C2_prime) * sin(deg2rad(delta_h_prime / 2.0));

    // Step 7: Calculate mean L', mean C', mean h'
    double L_prime_bar = (L1 + L2) / 2.0;
    double C_prime_bar = (C1_prime + C2_prime) / 2.0;

    double h_prime_bar;
    if (C1_prime * C2_prime == 0)
        h_prime_bar = h1_prime + h2_prime;
    else if (fabs(h1_prime - h2_prime) <= 180)
        h_prime_bar = (h1_prime + h2_prime) / 2.0;
    else if ((h1_prime + h2_prime) < 360)
        h_prime_bar = (h1_prime + h2_prime + 360) / 2.0;
    else
        h_prime_bar = (h1_prime + h2_prime - 360) / 2.0;

    // Step 8: Calculate T
    double T = 1 - 0.17 * _cos_deg(h_prime_bar - 30) +
                  0.24 * _cos_deg(2 * h_prime_bar) +
                  0.32 * _cos_deg(3 * h_prime_bar + 6) -
                  0.20 * _cos_deg(4 * h_prime_bar - 63);

    // Step 9: Calculate Delta Theta
    double delta_theta = 30 * exp(-((h_prime_bar - 275) / 25) * ((h_prime_bar - 275) / 25));

    // Step 10: Calculate R_C
    double C_prime_bar7 = pow(C_prime_bar, 7);
    double R_C = 2 * sqrt(C_prime_bar7 / (C_prime_bar7 + pow(25.0, 7)));

    // Step 11: Calculate S_L, S_C, S_H
    double S_L = 1 + ((0.015 * ((L_prime_bar - 50) * (L_prime_bar - 50))) / sqrt(20 + ((L_prime_bar - 50) * (L_prime_bar - 50))));
    double S_C = 1 + 0.045 * C_prime_bar;
    double S_H = 1 + 0.015 * C_prime_bar * T;

    // Step 12: Calculate R_T
    double R_T = -sin(deg2rad(2 * delta_theta)) * R_C;

    // Step 13: Final Delta E 2000
    double delta_E = sqrt(
        (delta_L_prime / S_L) * (delta_L_prime / S_L) +
        (delta_C_prime / S_C) * (delta_C_prime / S_C) +
        (delta_H_prime / S_H) * (delta_H_prime / S_H) +
        R_T * (delta_C_prime / S_C) * (delta_H_prime / S_H)
    );

    return delta_E;
}