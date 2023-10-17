#include "../include/vec4.hpp"

vec4::vec4() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
    e[3] = 0;
}

vec4::vec4(double e0, double e1, double e2, double e3) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
    e[3] = e3;
}

double vec4::w() const { return e[0]; }
double vec4::x() const { return e[1]; }
double vec4::y() const { return e[2]; }
double vec4::z() const { return e[3]; }

double vec4::operator[](int i) const { return e[i]; }
double& vec4::operator[](int i) { return e[i]; }

vec4 vec4::operator-() const {
    return vec4(-e[0], -e[1], -e[2], -e[3]);
}

vec4& vec4::operator+=(const vec4 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    e[3] += v.e[3];
    return *this;
}

vec4& vec4::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    e[3] *= t;
    return *this;
}

vec4& vec4::operator/=(double t) { return *this *= 1 / t; }

bool vec4::operator==(const vec4 &v) const {
    double abs_error = 1e-4;
    double diff0 = abs(e[0] - v.e[0]);
    double diff1 = abs(e[1] - v.e[1]);
    double diff2 = abs(e[2] - v.e[2]);
    double diff3 = abs(e[3] - v.e[3]);

    if(diff0 > abs_error || diff1 > abs_error
        || diff2 > abs_error || diff3 > abs_error)
        return false;

    return true;
}

double vec4::length() const { return sqrt(length_squared()); }

double vec4::length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2] + e[3] * e[3];
}