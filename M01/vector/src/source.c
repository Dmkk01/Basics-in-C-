#include <math.h>
#include <stdio.h>

double vectorlength(double x, double y, double z) {
    double x2 = x * x;
    double y2 = y * y;
    double z2 = z * z;
    return sqrt(x2 + y2 + z2);
}

