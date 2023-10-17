#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>
#include "vec2.hpp"

using namespace std;
using std::sqrt;

/// @brief Class for 2x2 matrices.
class mat2 {
    public:
        double e[2][2];

        /// @brief Constructor for a zero matrix.
        mat2();

        /// @brief Default constructor.
        /// @param e00 Value for position a11.
        /// @param e01 Value for position a12.
        /// @param e10 Value for position a21.
        /// @param e11 Value for position a22.
        mat2(double e00, double e01, double e10, double e11);

        /// @brief Getter for position a11.
        /// @return Value at position a11.
        double a11() const;

        /// @brief Getter for position a12.
        /// @return Value at position a12.
        double a12() const;

        /// @brief Getter for position a21.
        /// @return Value at position a21.
        double a21() const;

        /// @brief Getter for position a22.
        /// @return Value at position a22.
        double a22() const;

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
        mat2 T() const;

        /// @brief Operator for negative matrix.
        /// @return Negative matrix.
        mat2 operator-() const;

        /// @brief Compound assignment operator for matrix addition.
        /// @param a Matrix to add.
        /// @return This matrix plus given matrix.
        mat2& operator+=(const mat2 &a);

        /// @brief Compound assignment operator for matrix-scalar multiplication.
        /// @param t Scalar to multiply.
        /// @return This matrix multiplied by given scalar.
        mat2& operator*=(double t);

        /// @brief Compound assignment operator for matrix-scalar division.
        /// @param t Scalar to divide.
        /// @return This matrix divided by given scalar.
        mat2& operator/=(double t);

        /// @brief Operator for equality.
        /// @param v Vector to compare.
        /// @return True if this vector equals vector v, false otherwise.
        bool operator==(const mat2 &a) const;

        /// @brief Get determinant of this matrix.
        /// @return Value of determinant.
        double det() const;
};

/** Matrix Utility Functions **/

/// @brief Operator to print given matrix.
/// @param out Output object reference.
/// @param a Matrix.
/// @return Output stream.
inline std::ostream& operator<<(std::ostream &out, const mat2 &a) {
    return out << a(0, 0) << ' ' << a(0, 1) << '\n'
            << a(1, 0) << ' ' << a(1, 1) << '\n';
}

/// @brief Operator for matrix addition.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A plus matrix B.
inline mat2 operator+(const mat2 &a, const mat2 &b) {
    return mat2(a(0, 0) + b(0, 0), 
                a(0, 1) + b(0, 1), 
                a(1, 0) + b(1, 0),
                a(1, 1) + b(1, 1));
}

/// @brief Operator for matrix subtraction.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A minus matrix B.
inline mat2 operator-(const mat2 &a, const mat2 &b) {
    return mat2(a(0, 0) - b(0, 0), 
                a(0, 1) - b(0, 1), 
                a(1, 0) - b(1, 0),
                a(1, 1) - b(1, 1));
}

/// @brief Operator for matrix multiplication.
/// @param a Matrix A.
/// @param b Matrix B.
/// @return Matrix A multiplied by matrix B.
inline mat2 operator*(const mat2 &a, const mat2 &b) {
    return mat2(a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0), 
                a(0, 0) * b(0, 1) + a(0 ,1) * b(1, 1), 
                a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0), 
                a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1));
}

/// @brief Operator for matrix multiplication with a vector.
/// @param a Matrix A.
/// @param v Vector v.
/// @return Matrix A mutiplied by vector v.
inline vec2 operator*(const mat2 &a, const vec2 &v) {
    return vec2(a(0, 0) * v[0] + a(0, 1) * v[1], 
                a(1, 0) * v[0] + a(1, 1) * v[1]);
}

/// @brief Operator for matrix-scalar multiplication.
/// @param t Scalar t.
/// @param a Matrix A.
/// @return Matrix A multiplied by scalar t.
inline mat2 operator*(double t, const mat2 &a) {
    return mat2(t * a(0, 0), 
                t * a(0, 1),
                t * a(1, 0),
                t * a(1, 1));
}

/// @brief Operator for matrix-scalar multiplication (commutative).
/// @param a Matrix A.
/// @param t Scalar t.
/// @return Matrix A multiplied by scalar t.
inline mat2 operator*(const mat2 &a, double t) {
    return t * a;
}

/// @brief Operator for matrix-scalar division.
/// @param a Matrix A.
/// @param t Scalar t.
/// @return Matrix A divided by scalar t.
inline mat2 operator/(mat2 a, double t) {
    return (1 / t) * a;
}

#endif