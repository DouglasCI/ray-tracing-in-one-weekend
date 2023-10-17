#include "../include/vec2.hpp"

vec2::vec2() {
    e[0] = 0;
    e[1] = 0;
}

vec2::vec2(double e0, double e1) {
    e[0] = e0;
    e[1] = e1;
}

double vec2::x() const { return e[0]; }
double vec2::y() const { return e[1]; }

double vec2::operator[](int i) const { return e[i]; }
double& vec2::operator[](int i) { return e[i]; }

vec2 vec2::operator-() const { return vec2(-e[0], -e[1]); }

vec2& vec2::operator+=(const vec2 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    return *this;
}

vec2& vec2::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    return *this;
}

vec2& vec2::operator/=(double t) { return *this *= 1 / t; }

bool vec2::operator==(const vec2 &v) const{
    double abs_error = 1e-2;
    double diff0 = abs(e[0] - v.e[0]);
    double diff1 = abs(e[1] - v.e[1]);

    if(diff0 > abs_error || diff1 > abs_error)
        return false;

    return true;
}

double vec2::length() const { return sqrt(length_squared()); }

double vec2::length_squared() const {
    return e[0] * e[0] + e[1] * e[1];
}