#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>
#include "vec3.hpp"

using namespace std;
using std::sqrt;

/// @brief Class for 3x3 matrices.
class mat3 {
    public:
        double e[3][3];

        /// @brief Constructor for a zero matrix.
        mat3();

        /// @brief Default constructor.
        /// @param e00 Value for position a11.
        /// @param e01 Value for position a12.
        /// @param e02 Value for position a13.
        /// @param e10 Value for position a21.
        /// @param e11 Value for position a22.
        /// @param e12 Value for position a23.
        /// @param e20 Value for position a31.
        /// @param e21 Value for position a32.
        /// @param e22 Value for position a33.
        mat3(double e00, double e01, double e02,
             double e10, double e11, double e12,
             double e20, double e21, double e22);

        /// @brief Getter for position a11.
        /// @return Value at position a11.
        double a11() const;

        /// @brief Getter for position a12.
        /// @return Value at position a12.
        double a12() const;

        /// @brief Getter for position a13.
        /// @return Value at position a13.
        double a13() const;

        /// @brief Getter for position a21.
        /// @return Value at position a21.
        double a21() const;

        /// @brief Getter for position a22.
        /// @return Value at position a22.
        double a22() const;

        /// @brief Getter for position a23.
        /// @return Value at position a23.
        double a23() const;

        /// @brief Getter for position a31.
        /// @return Value at position a31.
        double a31() const;

        /// @brief Getter for position a32.
        /// @return Value at position a32.
        double a32() const;

        /// @brief Getter for position a33.
        /// @return Value at position a33.
        double a33() const;

        /// @brief Operator for getting a value in the matrix.
        /// @param i Index.
        /// @return Value at given index.
        double operator()(int i, int j) const;

        /// @brief Operator for getting a reference to a position in the matrix.
        /// @param i Index.
        /// @return Reference of position at given index.
        double& operator()(int i, int j);

        /// @brief Transpose this matrix.
        /// @return Transposed matrix.
        mat3 T() const;

        /// @brief Operator for negative matrix.
        /// @return Negative matrix.
        mat3 operator-() const;

        /// @brief Compound assignment operator for matrix addition.
        /// @param a Matrix to add.
        /// @return This matrix plus given matrix.
        mat3& operator+=(const mat3 &a);

        /// @brief Compound assignment operator for matrix-scalar multiplication.
        /// @param t Scalar to multiply.
        /// @return This matrix multiplied by given scalar.
        mat3& operator*=(double t);

        /// @brief Compound assignment operator for matrix-scalar division.
        /// @param t Scalar to divide.
        /// @return This matrix divided by given scalar.
        mat3& operator/=(double t);

        /// @brief Operator for equality.
        /// @param v Vector to compare.
        /// @return True if this vector equals vector v, false otherwise.
        bool operator==(const mat3 &a) const;

        /// @brief Get determinant of this matrix.
        /// @return Value of determinant.
        double det() const;
};

/** Matrix Utility Functions **/

/// @brief Operator to print given matrix.
/// @param out Output object reference.
/// @param a Matrix.
/// @return Output stream.
inline std::ostream& operator<<(std::ostream &out, const mat3 &a) {
    return out << a(0, 0) << ' ' << a(0, 1) << ' ' << a(0, 2) << '\n'
            << a(1, 0) << ' ' << a(1, 1) << ' ' << a(1, 2) << '\n'
            << a(2, 0) << ' ' << a(2, 1) << ' ' << a(2, 2) << '\n';
}

/// @brief Operator for matrix addition.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A plus matrix B.
inline mat3 operator+(const mat3 &a, const mat3 &b) {
    return mat3(a(0, 0) + b(0, 0),
                a(0, 1) + b(0, 1),
                a(0, 2) + b(0, 2),
                a(1, 0) + b(1, 0),
                a(1, 1) + b(1, 1),
                a(1, 2) + b(1, 2),
                a(2, 0) + b(2, 0),
                a(2, 1) + b(2, 1),
                a(2, 2) + b(2, 2));
}

/// @brief Operator for matrix subtraction.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A minus matrix B.
inline mat3 operator-(const mat3 &a, const mat3 &b) {
    return mat3(a(0, 0) - b(0, 0),
                a(0, 1) - b(0, 1),
                a(0, 2) - b(0, 2),
                a(1, 0) - b(1, 0),
                a(1, 1) - b(1, 1),
                a(1, 2) - b(1, 2),
                a(2, 0) - b(2, 0),
                a(2, 1) - b(2, 1),
                a(2, 2) - b(2, 2));
}

/// @brief Operator for matrix multiplication.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A multiplied by matrix B.
inline mat3 operator*(const mat3 &a, const mat3 &b) {
    mat3 c = mat3();

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int n = 0; n < 3; n++) {
                c(i, j) += a(i, n) * b(n, j);
            }
        }
    }

    return c;
}

/// @brief Operator for matrix multiplication with a vector.
/// @param a Matrix A.
/// @param v Vector v.
/// @return Matrix A mutiplied by vector v.
inline vec3 operator*(const mat3 &a, const vec3 &v) {
    vec3 u = vec3();

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            u[i] += a(i, j) * v[j];
        }
    }

    return u;
}

/// @brief Operator for matrix-scalar multiplication.
/// @param t Scalar t.
/// @param a Matrix A.
/// @return Matrix A multiplied by scalar t.
inline mat3 operator*(double t, const mat3 &a) {
    return mat3(t * a(0, 0), 
                t * a(0, 1),
                t * a(0, 2),
                t * a(1, 0),
                t * a(1, 1),
                t * a(1, 2),
                t * a(2, 0),
                t * a(2, 1),
                t * a(2, 2));
}

/// @brief Operator for matrix-scalar multiplication (commutative).
/// @param a Matrix A.
/// @param t Scalar t.
/// @return Matrix A multiplied by scalar t.
inline mat3 operator*(const mat3 &a, double t) {
    return t * a;
}

/// @brief Operator for matrix-scalar division.
/// @param a Matrix A.
/// @param t Scalar t.
/// @return Matrix A divided by scalar t.
inline mat3 operator/(mat3 a, double t) {
    return (1 / t) * a;
}

#endif