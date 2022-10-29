#include "laba2.h"
#include "cmath"
#include "stdlib.h"

namespace Lab2{

    const double pi = 3.14159265358979323846;

    double Archimedes::distance(const double rad) const{
        return abs(step * rad);

    }

    double Archimedes::sector_area(const double r1, const double r2) const{
        if(step == 0)
            return 0;
        else
            return (abs(pow(r1,3) - pow(r2,3)) / 6 / abs(step));
    }

    double Archimedes::figure_area(const int n) const{
        if(n == 0 || step == 0)
            return 0;
        return step * step * pow(2 * pi,3) / 6 * (double)(3 * n * (n-1) + 1);
    }

    double Archimedes::ring_area(const int n) const {
        if(n == 0 || step == 0)
            return 0;
        return step * step * pow(2 * pi,3) / 6 * pow(n,3);
    }

    double Archimedes::arc_length(const double rad) const{
        double foo = sqrt(1 + rad + rad);
        return abs(step) / 2 * abs(rad * log(foo) + log(rad + foo));
    }

    double Archimedes::radius_of_curvature(const double rad) const{
        return step * pow(1 + (rad * rad), (double)2/3) / (rad * rad + 2);
    }

}
