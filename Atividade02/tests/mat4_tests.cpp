#include <gtest/gtest.h>
#include "../include/mat4.hpp"
#include "../include/vec4.hpp"

namespace {
    TEST(mat4_tests, transpose) {
        mat4 a = mat4(1.777, 2, -4.4, 2,
                        20, -4, 12.3, 3,
                        -3, 2.15, 32, -2,
                        1, 2, 8, 5.4);
        mat4 expect = mat4(1.777, 20, -3, 1, 
                            2, -4, 2.15, 2,
                            -4.4, 12.3, 32, 8,
                            2, 3, -2, 5.4);

        EXPECT_EQ(a.T(), expect);
    }

    TEST(mat4_tests, negative_matrix) {
        mat4 a = mat4(1.777, 2, -4.4, 2,
                        20, -4, 12.3, 3,
                        -3, 2.15, 32, -2,
                        1, 2, 8, 5.4);
        mat4 expect = mat4(-1.777, -2, 4.4, -2,
                        -20, 4, -12.3, -3,
                        3, -2.15, -32, 2,
                        -1, -2, -8, -5.4);

        EXPECT_EQ(-a, expect);
    }

    TEST(mat4_tests, compound_add) {
        mat4 a = mat4(1.23, 2.3, -2, 0.4,
                        1, 4.5, -24, -0.3,
                        4, -2, 5.6, 4,
                        2, 1.7, 8.6, 5);
        mat4 b = mat4(2, 4.45, -1.45, 8,
                        -4.3, 23, 4, 7.5,
                        -9, 0, 12, 3,
                        -5, 6.4, 5, -1);
        a += b;

        mat4 expect = mat4(3.23, 6.75, -3.45, 8.4,
                            -3.3, 27.5, -20, 7.2,
                            -5, -2, 17.6, 7,
                            -3, 8.1, 13.6, 4);
        EXPECT_EQ(a, expect);
    }

    TEST(mat4_tests, compound_mult) {
        mat4 a = mat4(4, 7, 8, -1.2,
                        10, 2, 1, 4,
                        6, 8, 2.3, 5,
                        0, 4.1, 3, 6);
        a *= 3.123;

        mat4 expect = mat4(12.492, 21.861, 24.984, -3.7476,
                            31.23, 6.246, 3.123, 12.492,
                            18.738, 24.984, 7.1829, 15.615,
                            0, 12.8043, 9.369, 18.738);
        EXPECT_EQ(a, expect);
    }

    TEST(mat4_tests, compound_div) {
        mat4 a = mat4(4, 3.4, 10.8, 3.5,
                    -44.6, 4, 5, 3,
                    -9, 5.6, -1.2, -9.6,
                    1.2, 6, -6.6, 9);
        a /= 2;

        mat4 expect = mat4(2, 1.7, 5.4, 1.75,
                            -22.3, 2, 2.5, 1.5,
                            -4.5, 2.8, -0.6, -4.8,
                            0.6, 3, -3.3, 4.5);
        EXPECT_EQ(a, expect);
    }

    TEST(mat4_tests, determinant) {
        mat4 a = mat4(4, 3.4, 10.8, 1.3,
                        -44.6, 4, 2, -4,
                        0, -6, 4, 1,
                        11.2, 2, -2, 4.1);

        EXPECT_DOUBLE_EQ(a.det(), 12765.664);
    }

    TEST(mat4_tests, add) {
        mat4 a = mat4(1.23, 2.3, -2, 0.4,
                        1, 4.5, -24, -0.3,
                        4, -2, 5.6, 4,
                        2, 1.7, 8.6, 5);
        mat4 b = mat4(2, 4.45, -1.45, 8,
                        -4.3, 23, 4, 7.5,
                        -9, 0, 12, 3,
                        -5, 6.4, 5, -1);
        mat4 r = a + b;

        mat4 expect = mat4(3.23, 6.75, -3.45, 8.4,
                            -3.3, 27.5, -20, 7.2,
                            -5, -2, 17.6, 7,
                            -3, 8.1, 13.6, 4);
        EXPECT_EQ(r, expect);
    }

    TEST(mat4_tests, sub) {
        mat4 a = mat4(1.23, 2.3, -2, 0.4,
                        1, 4.5, -24, -0.3,
                        4, -2, 5.6, 4,
                        2, 1.7, 8.6, 5);
        mat4 b = mat4(2, 4.45, -1.45, 8,
                        -4.3, 23, 4, 7.5,
                        -9, 0, 12, 3,
                        -5, 6.4, 5, -1);
        mat4 r = a - b;
        
        mat4 expect = mat4(-0.77, -2.15, -0.55, -7.6,
                            5.3, -18.5, -28, -7.8,
                            13, -2, -6.4, 1,
                            7, -4.7, 3.6, 6);
        EXPECT_EQ(r, expect);
    }

    TEST(mat4_tests, matrix_mult) {
        mat4 a = mat4(5.12, -16.4, 44, -2,
                        0.68, -23, 4, 1,
                        0.4, 23, 5, 9,
                        1.2, -2, 4, -5);
        mat4 b = mat4(9.34, 17.13, 0.11, 4,
                        76, 1, 1, -2.3,
                        4, 9.3, -2, -1,
                        3.4, 3.14, 8, -7.6);
        mat4 r = a * b;

        mat4 expect = mat4(-1029.38, 474.226, -119.837, 29.4,
                            -1722.25, 28.9884, -22.9252, 44.02,
                            1802.34, 104.612, 85.044, -124.7,
                            -141.792, 40.056, -49.868, 43.4);
        EXPECT_EQ(r, expect);
    }

    TEST(mat4_tests, matrix_vector_mult) {
        mat4 a = mat4(5.12, -16.4, 44, 1,
                        0.68, 2, 9, -2.3,
                        -2, -9.4, 3, 5,
                        -0.1, 2, 4.5, 6);
        vec4 v = vec4(3.4, -7.42, 1, 7);
        vec4 r = a * v;

        vec4 expect = vec4(190.096, -19.628, 100.948, 31.32);
        EXPECT_EQ(r, expect);
    }

    TEST(mat4_tests, scalar_mult) {
        mat4 a = mat4(5.12, -16.4, -1.9, 1,
                        0.1, 5, 2, 9,
                        -1, 3.4, -9.4, 7.2,
                        5, 4.3, 2.1, 3);
        mat4 r = a * -2.2;

        mat4 expect = mat4(-11.264, 36.08, 4.18, -2.2,
                            -0.22, -11, -4.4, -19.8,
                            2.2, -7.48, 20.68, -15.84,
                            -11, -9.46, -4.62, -6.6);
        EXPECT_EQ(r, expect);
    }

    TEST(mat4_tests, scalar_mult_commutative) {
        mat4 a = mat4(5.12, -16.4, -1.9, 1,
                        0.1, 5, 2, 9,
                        -1, 3.4, -9.4, 7.2,
                        5, 4.3, 2.1, 3);
        mat4 r = -2.2 * a;

        mat4 expect = mat4(-11.264, 36.08, 4.18, -2.2,
                            -0.22, -11, -4.4, -19.8,
                            2.2, -7.48, 20.68, -15.84,
                            -11, -9.46, -4.62, -6.6);
        EXPECT_EQ(r, expect);
    }

    TEST(mat4_tests, scalar_div) {
        mat4 a = mat4(9.99, -19.2, 18.33, 3,
                        -27.96, 4.5, -1.5, 6.3,
                        24, 3, -3.3, -9.9,
                        6.9, 69, 9.3, -3);
        mat4 r = a / 3;

        mat4 expect = mat4(3.33, -6.4, 6.11, 1,
                            -9.32, 1.5, -0.5, 2.1,
                            8, 1, -1.1, -3.3,
                            2.3, 23, 3.1, -1);
        EXPECT_EQ(r, expect);
    }
}