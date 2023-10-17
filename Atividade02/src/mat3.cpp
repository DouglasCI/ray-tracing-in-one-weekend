#include "../include/mat3.hpp"

mat3::mat3() {
    e[0][0] = 0; e[0][1] = 0; e[0][2] = 0;
    e[1][0] = 0; e[1][1] = 0; e[1][2] = 0;
    e[2][0] = 0; e[2][1] = 0; e[2][2] = 0;
}

mat3::mat3(double e00, double e01, double e02,
            double e10, double e11, double e12,
            double e20, double e21, double e22) {
    e[0][0] = e00; e[0][1] = e01; e[0][2] = e02;
    e[1][0] = e10; e[1][1] = e11; e[1][2] = e12;
    e[2][0] = e20; e[2][1] = e21; e[2][2] = e22;
}

double mat3::a11() const { return e[0][0]; }
double mat3::a12() const { return e[0][1]; }
double mat3::a13() const { return e[0][2]; }
double mat3::a21() const { return e[1][0]; }
double mat3::a22() const { return e[1][1]; }
double mat3::a23() const { return e[1][2]; }
double mat3::a31() const { return e[2][0]; }
double mat3::a32() const { return e[2][1]; }
double mat3::a33() const { return e[2][2]; }

double mat3::operator()(int i, int j) const { return e[i][j]; }
double& mat3::operator()(int i, int j) { return e[i][j]; }

mat3 mat3::T() const { 
    return mat3(e[0][0], e[1][0], e[2][0],
                e[0][1], e[1][1], e[2][1],
                e[0][2], e[1][2], e[2][2]);
}

mat3 mat3::operator-() const {
    return mat3(-e[0][0], -e[0][1], -e[0][2],
                -e[1][0], -e[1][1], -e[1][2],
                -e[2][0], -e[2][1], -e[2][2]);
}

mat3& mat3::operator+=(const mat3 &a) {
    e[0][0] += a.e[0][0]; e[0][1] += a.e[0][1]; e[0][2] += a.e[0][2];
    e[1][0] += a.e[1][0]; e[1][1] += a.e[1][1]; e[1][2] += a.e[1][2];
    e[2][0] += a.e[2][0]; e[2][1] += a.e[2][1]; e[2][2] += a.e[2][2];
    return *this;
}

mat3& mat3::operator*=(double t) {
    e[0][0] *= t; e[0][1] *= t; e[0][2] *= t;
    e[1][0] *= t; e[1][1] *= t; e[1][2] *= t;
    e[2][0] *= t; e[2][1] *= t; e[2][2] *= t;
    return *this;
}

mat3& mat3::operator/=(double t) { return *this *= 1 / t; }

bool mat3::operator==(const mat3 &a) const {
    double abs_error = 1e-1;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            double diff = abs(e[i][j] - a.e[i][j]);
            
            if(diff > abs_error)
                return false;
        }
    }

    return true;
}

double mat3::det() const {
    return e[0][0] * (e[1][1] * e[2][2] - e[1][2] * e[2][1])
        - e[0][1] * (e[1][0] * e[2][2] - e[1][2] * e[2][0])
        + e[0][2] * (e[1][0] * e[2][1] - e[1][1] * e[2][0]);
}