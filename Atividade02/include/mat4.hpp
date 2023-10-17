#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>
#include "vec4.hpp"

using namespace std;
using std::sqrt;

/// @brief Class for 4x4 matrices.
class mat4 {
    public:
        double e[4][4];

        /// @brief Constructor for a zero matrix.
        mat4();

        /// @brief 
        /// @param e00 Value for position a11.
        /// @param e01 Value for position a12.
        /// @param e02 Value for position a13.
        /// @param e03 Value for position a14.
        /// @param e10 Value for position a21.
        /// @param e11 Value for position a22.
        /// @param e12 Value for position a23.
        /// @param e13 Value for position a24.
        /// @param e20 Value for position a31.
        /// @param e21 Value for position a32.
        /// @param e22 Value for position a33.
        /// @param e23 Value for position a34.
        /// @param e30 Value for position a41.
        /// @param e31 Value for position a42.
        /// @param e32 Value for position a43.
        /// @param e33 Value for position a44.
        mat4(double e00, double e01, double e02, double e03,
             double e10, double e11, double e12, double e13,
             double e20, double e21, double e22, double e23,
             double e30, double e31, double e32, double e33);

        /// @brief Getter for position a11.
        /// @return Value at position a11.
        double a11() const;

        /// @brief Getter for position a12.
        /// @return Value at position a12.
        double a12() const;

        /// @brief Getter for position a13.
        /// @return Value at position a13.
        double a13() const;

        /// @brief Getter for position a14.
        /// @return Value at position a14.
        double a14() const;

        /// @brief Getter for position a21.
        /// @return Value at position a21.
        double a21() const;

        /// @brief Getter for position a22.
        /// @return Value at position a22.
        double a22() const;

        /// @brief Getter for position a23.
        /// @return Value at position a23.
        double a23() const;

        /// @brief Getter for position a24.
        /// @return Value at position a24.
        double a24() const;

        /// @brief Getter for position a31.
        /// @return Value at position a31.
        double a31() const;

        /// @brief Getter for position a32.
        /// @return Value at position a32.
        double a32() const;

        /// @brief Getter for position a33.
        /// @return Value at position a33.
        double a33() const;

        /// @brief Getter for position a34.
        /// @return Value at position a34.
        double a34() const;

        /// @brief Getter for position a41.
        /// @return Value at position a41.
        double a41() const;

        /// @brief Getter for position a42.
        /// @return Value at position a42.
        double a42() const;

        /// @brief Getter for position a43.
        /// @return Value at position a43.
        double a43() const;

        /// @brief Getter for position a44.
        /// @return Value at position a44.
        double a44() const;

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
        mat4 T() const;

        /// @brief Operator for negative matrix.
        /// @return Negative matrix.
        mat4 operator-() const;

        /// @brief Compound assignment operator for matrix addition.
        /// @param a Matrix to add.
        /// @return This matrix plus given matrix.
        mat4& operator+=(const mat4 &a);

        /// @brief Compound assignment operator for matrix-scalar multiplication.
        /// @param t Scalar to multiply.
        /// @return This matrix multiplied by given scalar.
        mat4& operator*=(double t);

        /// @brief Compound assignment operator for matrix-scalar division.
        /// @param t Scalar to divide.
        /// @return This matrix divided by given scalar.
        mat4& operator/=(double t);

        /// @brief Operator for equality.
        /// @param v Vector to compare.
        /// @return True if this vector equals vector v, false otherwise.
        bool operator==(const mat4 &a) const;

        /// @brief Get determinant of this matrix.
        /// @return Value of determinant.
        double det() const;
};

/** Matrix Utility Functions **/

/// @brief Operator to print given matrix.
/// @param out Output object reference.
/// @param a Matrix.
/// @return Output stream.
inline std::ostream& operator<<(std::ostream &out, const mat4 &a) {
    return out << a(0, 0) << ' ' << a(0, 1) << ' ' << a(0, 2) << ' ' << a(0, 3) << '\n'
            << a(1, 0) << ' ' << a(1, 1) << ' ' << a(1, 2) << ' ' << a(1, 3) << '\n'
            << a(2, 0) << ' ' << a(2, 1) << ' ' << a(2, 2) << ' ' << a(2, 3) << '\n'
            << a(3, 0) << ' ' << a(3, 1) << ' ' << a(3, 2) << ' ' << a(3, 3) << '\n';
}

/// @brief Operator for matrix addition.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A plus matrix B.
inline mat4 operator+(const mat4 &a, const mat4 &b) {
    mat4 c = mat4();

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            c(i, j) = a(i, j) + b(i, j);
        }
    }

    return c;
}

/// @brief Operator for matrix subtraction.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A minus matrix B.
inline mat4 operator-(const mat4 &a, const mat4 &b) {
    mat4 c = mat4();

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            c(i, j) = a(i, j) - b(i, j);
        }
    }

    return c;
}

/// @brief Operator for matrix multiplication.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A multiplied by matrix B.
inline mat4 operator*(const mat4 &a, const mat4 &b) {
    mat4 c = mat4();

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            for(int n = 0; n < 4; n++) {
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
inline vec4 operator*(const mat4 &a, const vec4 &v) {
    vec4 u = vec4();

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            u[i] += a(i, j) * v[j];
        }
    }

    return u;
}

/// @brief Operator for matrix-scalar multiplication.
/// @param t Scalar t.
/// @param a Matrix A.
/// @return Matrix A multiplied by scalar t.
inline mat4 operator*(double t, const mat4 &a) {
    mat4 c = mat4();

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            c(i, j) = t * a(i, j);
        }
    }

    return c;
}

/// @brief Operator for matrix-scalar multiplication (commutative).
/// @param a Matrix A.
/// @param t Scalar t.
/// @return Matrix A multiplied by scalar t.
inline mat4 operator*(const mat4 &a, double t) {
    return t * a;
}

/// @brief Operator for matrix-scalar division.
/// @param a Matrix A.
/// @param t Scalar t.
/// @return Matrix A divided by scalar t.
inline mat4 operator/(mat4 a, double t) {
    return (1 / t) * a;
}

#endif