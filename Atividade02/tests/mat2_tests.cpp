#include <gtest/gtest.h>
#include "../include/mat2.hpp"
#include "../include/vec2.hpp"

namespace {
    TEST(mat2_tests, transpose) {
        mat2 a = mat2(1.777, 2, -4.4, 20);
        mat2 expect = mat2(1.777, -4.4, 2, 20);

        EXPECT_EQ(a.T(), expect);
    }

    TEST(mat2_tests, negative_matrix) {
        mat2 a = mat2(1.777, 2, -4.4, 20);

        mat2 expect = mat2(-1.777, -2, 4.4, -20);
        EXPECT_EQ(-a, expect);
    }

    TEST(mat2_tests, compound_add) {
        mat2 a = mat2(1.23, 2.3, -2, 1);
        mat2 b = mat2(2, 4.12345, -1.45, -4.3);
        a += b;

        mat2 expect = mat2(3.23, 6.42345, -3.45, -3.3);
        EXPECT_EQ(a, expect);
    }

    TEST(mat2_tests, compound_mult) {
        mat2 a = mat2(4, 7, 8, 10);
        a *= 3.123;

        mat2 expect = mat2(12.492, 21.861, 24.984, 31.23);
        EXPECT_EQ(a, expect);
    }

    TEST(mat2_tests, compound_div) {
        mat2 a = mat2(4, 3.4, 10.8, -44.6);
        a /= 2;

        mat2 expect = mat2(2, 1.7, 5.4, -22.3);
        EXPECT_EQ(a, expect);
    }

    TEST(mat2_tests, determinant) {
        mat2 a = mat2(4, 3.4, 10.8, -44.6);

        EXPECT_DOUBLE_EQ(a.det(), -215.12);
    }

    TEST(mat2_tests, add) {
        mat2 a = mat2(5.12, 12.1, -7.3, 0);
        mat2 b = mat2(16, 17.13, 9, 3.57);
        mat2 r = a + b;

        mat2 expect = mat2(21.12, 29.23, 1.7, 3.57);
        EXPECT_EQ(r, expect);
    }

    TEST(mat2_tests, sub) {
        mat2 a = mat2(5.12, 256.2, -4.32, 0);
        mat2 b = mat2(16, 17.13, -80, 23.1);
        mat2 r = a - b;

        mat2 expect = mat2(-10.88, 239.07, 75.68, -23.1);
        EXPECT_EQ(r, expect);
    }

    TEST(mat2_tests, matrix_mult) {
        mat2 a = mat2(5.12, -16.4, 444, 0.68);
        mat2 b = mat2(90.234, 17.13, 0.11, 756);
        mat2 r = a * b;

        mat2 expect = mat2(460.194, -12310.7, 40064, 8119.8);
        EXPECT_EQ(r, expect);
    }

    TEST(mat2_tests, matrix_vector_mult) {
        mat2 a = mat2(5.12, -16.4, 444, 0.68);
        vec2 v = vec2(3.4, -76.42);
        vec2 r = a * v;

        vec2 expect = vec2(1270.7, 1457.63);
        EXPECT_EQ(r, expect);
    }

    TEST(mat2_tests, scalar_mult) {
        mat2 a = mat2(5.12, -16.4, -1.9, 0.1);
        mat2 r = a * 2.2;

        mat2 expect = mat2(11.264, -36.08, -4.18, 0.22);
        EXPECT_EQ(r, expect);
    }

    TEST(mat2_tests, scalar_mult_commutative) {
        mat2 a = mat2(5.12, -16.4, -1.9, 0.1);
        mat2 r = 2.2 * a;

        mat2 expect = mat2(11.264, -36.08, -4.18, 0.22);
        EXPECT_EQ(r, expect);
    }

    TEST(mat2_tests, scalar_div) {
        mat2 a = mat2(9.99, -19.2, 18.33, -27.96);
        mat2 r = a / 3;

        mat2 expect = mat2(3.33, -6.4, 6.11, -9.32);
        EXPECT_EQ(r, expect);
    }
}