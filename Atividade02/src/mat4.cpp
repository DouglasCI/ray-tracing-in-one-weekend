#include "../include/mat4.hpp"

mat4::mat4() {
    e[0][0] = 0; e[0][1] = 0; e[0][2] = 0; e[0][3] = 0;
    e[1][0] = 0; e[1][1] = 0; e[1][2] = 0; e[1][3] = 0;
    e[2][0] = 0; e[2][1] = 0; e[2][2] = 0; e[2][3] = 0;
    e[3][0] = 0; e[3][1] = 0; e[3][2] = 0; e[3][3] = 0;
}

mat4::mat4(double e00, double e01, double e02, double e03,
            double e10, double e11, double e12, double e13,
            double e20, double e21, double e22, double e23,
            double e30, double e31, double e32, double e33) {
    e[0][0] = e00; e[0][1] = e01; e[0][2] = e02; e[0][3] = e03;
    e[1][0] = e10; e[1][1] = e11; e[1][2] = e12; e[1][3] = e13;
    e[2][0] = e20; e[2][1] = e21; e[2][2] = e22; e[2][3] = e23;
    e[3][0] = e30; e[3][1] = e31; e[3][2] = e32; e[3][3] = e33;
}

double mat4::a11() const { return e[0][0]; }
double mat4::a12() const { return e[0][1]; }
double mat4::a13() const { return e[0][2]; }
double mat4::a14() const { return e[0][3]; }
double mat4::a21() const { return e[1][0]; }
double mat4::a22() const { return e[1][1]; }
double mat4::a23() const { return e[1][2]; }
double mat4::a24() const { return e[1][3]; }
double mat4::a31() const { return e[2][0]; }
double mat4::a32() const { return e[2][1]; }
double mat4::a33() const { return e[2][2]; }
double mat4::a34() const { return e[2][3]; }
double mat4::a41() const { return e[3][0]; }
double mat4::a42() const { return e[3][1]; }
double mat4::a43() const { return e[3][2]; }
double mat4::a44() const { return e[3][3]; }

double mat4::operator()(int i, int j) const { return e[i][j]; }
double& mat4::operator()(int i, int j) { return e[i][j]; }

mat4 mat4::T() const { 
    return mat4(e[0][0], e[1][0], e[2][0], e[3][0],
                e[0][1], e[1][1], e[2][1], e[3][1],
                e[0][2], e[1][2], e[2][2], e[3][2],
                e[0][3], e[1][3], e[2][3], e[3][3]);
}

mat4 mat4::operator-() const {
    return mat4(-e[0][0], -e[0][1], -e[0][2], -e[0][3],
                -e[1][0], -e[1][1], -e[1][2], -e[1][3],
                -e[2][0], -e[2][1], -e[2][2], -e[2][3],
                -e[3][0], -e[3][1], -e[3][2], -e[3][3]);
}

mat4& mat4::operator+=(const mat4 &a) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            e[i][j] += a.e[i][j];
        }
    }
    return *this;
}

mat4& mat4::operator*=(double t) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            e[i][j] *= t;
        }
    }
    return *this;
}

mat4& mat4::operator/=(double t) { return *this *= 1 / t; }

bool mat4::operator==(const mat4 &a) const {
    double abs_error = 1e-1;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            double diff = abs(e[i][j] - a.e[i][j]);
            
            if(diff > abs_error)
                return false;
        }
    }

    return true;
}

double mat4::det() const {
    return e[0][3] * e[1][2] * e[2][1] * e[3][0] - e[0][2] * e[1][3] * e[2][1] * e[3][0] -
        e[0][3] * e[1][1] * e[2][2] * e[3][0] + e[0][1] * e[1][3] * e[2][2] * e[3][0] +
        e[0][2] * e[1][1] * e[2][3] * e[3][0] - e[0][1] * e[1][2] * e[2][3] * e[3][0] -
        e[0][3] * e[1][2] * e[2][0] * e[3][1] + e[0][2] * e[1][3] * e[2][0] * e[3][1] +
        e[0][3] * e[1][0] * e[2][2] * e[3][1] - e[0][0] * e[1][3] * e[2][2] * e[3][1] -
        e[0][2] * e[1][0] * e[2][3] * e[3][1] + e[0][0] * e[1][2] * e[2][3] * e[3][1] +
        e[0][3] * e[1][1] * e[2][0] * e[3][2] - e[0][1] * e[1][3] * e[2][0] * e[3][2] -
        e[0][3] * e[1][0] * e[2][1] * e[3][2] + e[0][0] * e[1][3] * e[2][1] * e[3][2] +
        e[0][1] * e[1][0] * e[2][3] * e[3][2] - e[0][0] * e[1][1] * e[2][3] * e[3][2] -
        e[0][2] * e[1][1] * e[2][0] * e[3][3] + e[0][1] * e[1][2] * e[2][0] * e[3][3] +
        e[0][2] * e[1][0] * e[2][1] * e[3][3] - e[0][0] * e[1][2] * e[2][1] * e[3][3] -
        e[0][1] * e[1][0] * e[2][2] * e[3][3] + e[0][0] * e[1][1] * e[2][2] * e[3][3];
}