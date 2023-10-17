#ifndef VEC4_H
#define VEC4_H

#include <cmath>
#include <iostream>

using namespace std;
using std::sqrt;

/// @brief Class for 4D vectors.
class vec4 {
    public:
        double e[4];

        /// @brief Constructor for a zero vector.
        vec4();

        /// @brief Default constructor.
        /// @param e0 Value for position 1.
        /// @param e1 Value for position 2.
        /// @param e2 Value for position 3.
        /// @param e3 Value for position 4.
        vec4(double e0, double e1, double e2, double e3);

        /// @brief Getter for position 1.
        /// @return Value at position 1.
        double w() const;

        /// @brief Getter for position 2.
        /// @return Value at position 2.
        double x() const;

        /// @brief Getter for position 3.
        /// @return Value at position 3.
        double y() const;

        /// @brief Getter for position 4.
        /// @return Value at position 4.
        double z() const;

        /// @brief Operator for getting a value in the vector.
        /// @param i Index.
        /// @return Value at given index.
        double operator[](int i) const;

        /// @brief Operator for getting a reference to a position in the vector.
        /// @param i Index.
        /// @return Reference of position at given index.
        double& operator[](int i);

        /// @brief Operator for negative vector.
        /// @return Negative vector.
        vec4 operator-() const;

        /// @brief Compound assignment operator for vector addition.
        /// @param v Vector to add.
        /// @return This vector plus given vector.
        vec4& operator+=(const vec4 &v);

        /// @brief Compound assignment operator for vector-scalar multiplication.
        /// @param v Vector to multiply.
        /// @return This vector mutiplied by given scalar.
        vec4& operator*=(double t);

        /// @brief Compound assignment operator for vector-scalar division.
        /// @param v Vector to divide.
        /// @return This vector divided by given scalar.
        vec4& operator/=(double t);

        /// @brief Operator for equality.
        /// @param v Vector to compare.
        /// @return True if this vector equals vector v, false otherwise.
        bool operator==(const vec4 &v) const;

        /// @brief Get length (magnitude) of this vector.
        /// @return Value of length.
        double length() const;

        /// @brief Get sum of squared components of this vector.
        /// @return Value of sum of squared components.
        double length_squared() const;
};

/* Vector Utility Functions */

/// @brief Operator to print given vector.
/// @param out Output object reference.
/// @param v Vector.
/// @return Output stream.
inline std::ostream& operator<<(std::ostream &out, const vec4 &v) {
    return out << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << '\n';
}

/// @brief Operator for vector addition.
/// @param u Vector u.
/// @param v Vector v.
/// @return Vector u plus vector v.
inline vec4 operator+(const vec4 &u, const vec4 &v) {
    return vec4(u[0] + v[0], 
                u[1] + v[1], 
                u[2] + v[2], 
                u[3] + v[3]);
}

/// @brief Operator for vector subtraction.
/// @param u Vector u.
/// @param v Vector v.
/// @return Vector u minus vector v.
inline vec4 operator-(const vec4 &u, const vec4 &v) {
    return vec4(u[0] - v[0], 
                u[1] - v[1], 
                u[2] - v[2], 
                u[3] - v[3]);
}

/// @brief Operator for vector element-wise multiplication.
/// @param u Vector u.
/// @param v Vector v.
/// @return Element-wise multiplication of vector u and v.
inline vec4 operator*(const vec4 &u, const vec4 &v) {
    return vec4(u[0] * v[0], 
                u[1] * v[1], 
                u[2] * v[2], 
                u[3] * v[3]);
}

/// @brief Operator for vector-scalar multiplication.
/// @param t Scalar t.
/// @param v Vector v.
/// @return Vector v multiplied by scalar t.
inline vec4 operator*(double t, const vec4 &v) {
    return vec4(t * v[0], t * v[1], t * v[2], t * v[3]);
}

/// @brief Operator for vector-scalar multiplication (commutative).
/// @param v Vector v.
/// @param t Scalar t.
/// @return Vector v multiplied by scalar t.
inline vec4 operator*(const vec4 &v, double t) {
    return t * v;
}

/// @brief Operator for vector-scalar division.
/// @param t Scalar t.
/// @param v Vector v.
/// @return Vector v divided by scalar t.
inline vec4 operator/(vec4 v, double t) {
    return (1 / t) * v;
}

/// @brief Dot product of two vectors.
/// @param u Vector u.
/// @param v Vector v.
/// @return Value of dot product.
inline double dot(const vec4 &u, const vec4 &v) {
    return u[0] * v[0]
         + u[1] * v[1]
         + u[2] * v[2]
         + u[3] * v[3];
}

/// @brief Get unit vector (length == 1).
/// @param v Vector.
/// @return Unit vector.
inline vec4 unit_vector(vec4 v) {
    return v / v.length();
}

#endif