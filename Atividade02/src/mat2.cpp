#include "../include/mat2.hpp"

mat2::mat2() {
    e[0][0] = 0; e[0][1] = 0;
    e[1][0] = 0; e[1][1] = 0;
}

mat2::mat2(double e0, double e1, double e2, double e3) {
    e[0][0] = e0; e[0][1] = e1;
    e[1][0] = e2; e[1][1] = e3;
}

double mat2::a11() const { return e[0][0]; }
double mat2::a12() const { return e[0][1]; }
double mat2::a21() const { return e[1][0]; }
double mat2::a22() const { return e[1][1]; }

double mat2::operator()(int i, int j) const { return e[i][j]; }
double& mat2::operator()(int i, int j) { return e[i][j]; }

mat2 mat2::T() const { return mat2(e[0][0], e[1][0], e[0][1], e[1][1]); }

mat2 mat2::operator-() const {
    return mat2(-e[0][0], -e[0][1], -e[1][0], -e[1][1]);
}

mat2& mat2::operator+=(const mat2 &a) {
    e[0][0] += a.e[0][0];
    e[0][1] += a.e[0][1];
    e[1][0] += a.e[1][0];
    e[1][1] += a.e[1][1];
    return *this;
}

mat2& mat2::operator*=(double t) {
    e[0][0] *= t;
    e[0][1] *= t;
    e[1][0] *= t;
    e[1][1] *= t;
    return *this;
}

mat2& mat2::operator/=(double t) { return *this *= 1 / t; }

bool mat2::operator==(const mat2 &a) const {
    double abs_error = 3e-2;
    double diff0 = abs(e[0][0] - a.e[0][0]);
    double diff1 = abs(e[0][1] - a.e[0][1]);
    double diff2 = abs(e[1][0] - a.e[1][0]);
    double diff3 = abs(e[1][1] - a.e[1][1]);

    if(diff0 > abs_error || diff1 > abs_error
        || diff2 > abs_error || diff3 > abs_error)
        return false;
    
    return true;
}

double mat2::det() const { return e[0][0] * e[1][1] - e[0][1] * e[1][0]; }