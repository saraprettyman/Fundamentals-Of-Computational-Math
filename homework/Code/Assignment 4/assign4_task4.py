#include <math.h>
#include <limits.h>

double absolute_error(double u, double v){
    return fabs(u - v);
}

double releer(double u, double v){
    if (u == 0) {
        return LLONG_MAX;
    }
    return (fabs(u - v)/u);
}

int dprecision(double u, double v) {
    double diff = fabs(u - v);
    double dpower = log10l(diff);
    double upower = log10l(u);
    return (floor(upower - dpower));
}

int fprecision(float u, float v) {
    float diff = fabs(u -v);
    float dpower = log10f(diff);
    float upower = log10f(u);
    return (floor(upower - dpower));
}
