#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>
#include "commons.hpp"

using namespace std;
using std::sqrt;

/// @brief Class for 3D vectors.
class vec3 {
    public:
        double e[3]; //!< Data structure

        /// @brief Constructor for a zero vector.
        vec3() {
            e[0] = 0;
            e[1] = 0;
            e[2] = 0;
        }

        /// @brief Default constructor.
        /// @param e0 Value for position 1.
        /// @param e1 Value for position 2.
        /// @param e2 Value for position 3.
        vec3(double e0, double e1, double e2) {
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }

        /// @brief Getter for position 1.
        /// @return Value at position 1.
        double x() const { return e[0]; }

        /// @brief Getter for position 2.
        /// @return Value at position 2.
        double y() const { return e[1]; }

        /// @brief Getter for position 3.
        /// @return Value at position 3.
        double z() const { return e[2]; }

        /// @brief Operator for getting a value in the vector.
        /// @param i Index.
        /// @return Value at given index.
        double operator[](int i) const { return e[i]; }

        /// @brief Operator for getting a reference to a position in the vector.
        /// @param i Index.
        /// @return Reference of position at given index.
        double& operator[](int i) { return e[i]; }

        /// @brief Operator for negative vector.
        /// @return Negative vector.
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        /// @brief Compound assignment operator for vector addition.
        /// @param v Vector to add.
        /// @return This vector plus given vector.
        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        /// @brief Compound assignment operator for vector-scalar multiplication.
        /// @param v Vector to multiply.
        /// @return This vector mutiplied by given scalar.
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        /// @brief Compound assignment operator for vector-scalar division.
        /// @param v Vector to divide.
        /// @return This vector divided by given scalar.
        vec3& operator/=(double t) { return *this *= 1 / t; }

        /// @brief Operator for equality.
        /// @param v Vector to compare.
        /// @return True if this vector equals vector v, false otherwise.
        bool operator==(const vec3 &v) const {
            double abs_error = 1e-2;
            double diff0 = abs(e[0] - v.e[0]);
            double diff1 = abs(e[1] - v.e[1]);
            double diff2 = abs(e[2] - v.e[2]);

            if(diff0 > abs_error || diff1 > abs_error || diff2 > abs_error)
                return false;

            return true;
        }

        /// @brief Get length (magnitude) of this vector.
        /// @return Value of length.
        double length() const { return sqrt(length_squared()); }

        /// @brief Get sum of squared components of this vector.
        /// @return Value of sum of squared components.
        double length_squared() const {
            return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
        }

        /// @brief Check if this vector is almost a zero vector.
        /// @return True if it is.
        bool near_zero() const {
            auto s = 1e-8;
            return (fabs(e[0]) < s) && (fabs(e[1]) < s) && (fabs(e[2]) < s);
        }

        /// @brief Generate a random vector.
        /// @return Random vector.
        static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }

        /// @brief Generate a random vector in a interval.
        /// @param min Minimum value.
        /// @param max Maximum value.
        /// @return Random vector.
        static vec3 random(double min, double max) {
            return vec3(random_double(min,max), random_double(min,max), random_double(min,max));
        }
};

// Alias
using point3 = vec3;

/* Vector Utility Functions */

/// @brief Operator to print given vector.
/// @param out Output object reference.
/// @param v Vector.
/// @return Output stream.
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

/// @brief Operator for vector addition.
/// @param u Vector u.
/// @param v Vector v.
/// @return Vector u plus vector v.
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u[0] + v[0], 
                u[1] + v[1], 
                u[2] + v[2]);
}

/// @brief Operator for vector subtraction.
/// @param u Vector u.
/// @param v Vector v.
/// @return Vector u minus vector v.
inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u[0] - v[0], 
                u[1] - v[1], 
                u[2] - v[2]);
}

/// @brief Operator for vector element-wise multiplication.
/// @param u Vector u.
/// @param v Vector v.
/// @return Element-wise multiplication of vector u and v.
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u[0] * v[0], 
                u[1] * v[1], 
                u[2] * v[2]);
}

/// @brief Operator for vector-scalar multiplication.
/// @param t Scalar t.
/// @param v Vector v.
/// @return Vector v multiplied by scalar t.
inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v[0], t * v[1], t * v[2]);
}

/// @brief Operator for vector-scalar multiplication (commutative).
/// @param v Vector v.
/// @param t Scalar t.
/// @return Vector v multiplied by scalar t.
inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

/// @brief Operator for vector-scalar division.
/// @param t Scalar t.
/// @param v Vector v.
/// @return Vector v divided by scalar t.
inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}

/// @brief Dot product of two vectors.
/// @param u Vector u.
/// @param v Vector v.
/// @return Value of dot product.
inline double dot(const vec3 &u, const vec3 &v) {
    return u[0] * v[0]
         + u[1] * v[1]
         + u[2] * v[2];
}

/// @brief Cross product of two vectors.
/// @param u Vector u.
/// @param v Vector v.
/// @return Resultant vector of cross product.
inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u[1] * v[2] - u[2] * v[1],
                u[2] * v[0] - u[0] * v[2],
                u[0] * v[1] - u[1] * v[0]);
}

/// @brief Get unit vector (length == 1).
/// @param v Vector.
/// @return Unit vector.
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

/// @brief Generate a random vector inside of the unit sphere.
/// @return Random vector.
inline vec3 random_in_unit_sphere() {
    // Keep trying until we find a vector inside the unit sphere
    while(true) {
        auto p = vec3::random(-1,1);
        if(p.length_squared() < 1)
            return p;
    }
}

/// @brief Generate a random vector normalized to be ON the unit sphere.
/// @return Random vector.
inline vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

/// @brief Generate random vector ON the unit sphere and in the correct hemisphere.
/// @param normal Surface's normal.
/// @return Random vector.
inline vec3 random_on_hemisphere(const vec3& normal) {
    vec3 on_unit_sphere = random_unit_vector();
    // In the same hemisphere as the normal
    if(dot(on_unit_sphere, normal) > 0.0) 
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

/// @brief Get a ray reflected from the surface.
/// @param v Incoming ray.
/// @param n Surface's normal.
/// @return Reflected ray.
inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v, n)*n;
}

inline vec3 refract(const vec3& uv, const vec3& n, double eta_over_etaprime) {
    double cos_theta = fmin(dot(-uv, n), 1.0);
    vec3 r_out_perp =  eta_over_etaprime * (uv + cos_theta*n);
    vec3 r_out_para = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_para;
}

#endif