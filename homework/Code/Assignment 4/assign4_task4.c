#include <stdio.h>
#include <math.h>
#include <limits.h>

double absolute_error(double u, double v) {
    double abs_error = fabs(u - v);
    printf("%f\n", abs_error);
    return 0;
}

double relative_error(double u, double v) {
    if (u == 0) {
        return LLONG_MAX;
    }
    double rel_error = (fabs(u - v)/u);
    printf("%f\n", rel_error);
    return 0;
}

int double_precision(double u, double v) {
    double diff = fabs(u - v);
    double dpower = log10l(diff);
    double upower = log10l(u);
    double d_precision = (floor(upower - dpower));
    printf("%f\n", d_precision);
    return 0;
}

int float_precision(float u, float v) {
    float diff = fabs(u -v);
    float dpower = log10f(diff);
    float upower = log10f(u);
    float f_precision = (floor(upower - dpower));
    printf("%f\n", f_precision);
    return 0;
}

double main() {
    double u = 12.0;
    double v = 4.0;
    absolute_error(u,v);
    relative_error(u,v);
    double_precision(u,v);
    float_precision(u,v);
}
