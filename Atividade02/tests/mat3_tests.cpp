#include <gtest/gtest.h>
#include "../include/mat3.hpp"
#include "../include/vec3.hpp"

namespace {
    TEST(mat3_tests, transpose) {
        mat3 a = mat3(1.777, 2, -4.4, 
                        20, -4, 12.3, 
                        -3, 2.15, 32);
        mat3 expect = mat3(1.777, 20, -3, 
                            2, -4, 2.15,
                            -4.4, 12.3, 32);

        EXPECT_EQ(a.T(), expect);
    }

    TEST(mat3_tests, negative_matrix) {
        mat3 a = mat3(1.777, 2, -4.4, 
                        20, -4, 12.3, 
                        -3, 2.15, 32);
        mat3 expect = mat3(-1.777, -2, 4.4, 
                            -20, 4, -12.3, 
                            3, -2.15, -32);

        EXPECT_EQ(-a, expect);
    }

    TEST(mat3_tests, compound_add) {
        mat3 a = mat3(1.23, 2.3, -2, 
                        1, 4.5, -24,
                        4, -2, 5.6);
        mat3 b = mat3(2, 4.45, -1.45, 
                        -4.3, 23, 4,
                        -9, 0, 12);
        a += b;

        mat3 expect = mat3(3.23, 6.75, -3.45,
                            -3.3, 27.5, -20,
                            -5, -2, 17.6);
        EXPECT_EQ(a, expect);
    }

    TEST(mat3_tests, compound_mult) {
        mat3 a = mat3(4, 7, 8,
                        10, 2, 1,
                        6, 8, 2.3);
        a *= 3.123;

        mat3 expect = mat3(12.492, 21.861, 24.984,
                            31.23, 6.246, 3.123,
                            18.738, 24.984, 7.1829);
        EXPECT_EQ(a, expect);
    }

    TEST(mat3_tests, compound_div) {
        mat3 a = mat3(4, 3.4, 10.8,
                    -44.6, 4, 5,
                    -9, 5.6, -1.2);
        a /= 2;

        mat3 expect = mat3(2, 1.7, 5.4, 
                            -22.3, 2, 2.5,
                            -4.5, 2.8, -0.6);
        EXPECT_EQ(a, expect);
    }

    TEST(mat3_tests, determinant) {
        mat3 a = mat3(4, 3.4, 10.8,
                        -44.6, 4, 2,
                        0, -6, 4);

        EXPECT_DOUBLE_EQ(a.det(), 3608.64);
    }

    TEST(mat3_tests, add) {
        mat3 a = mat3(1.23, 2.3, -2, 
                        1, 4.5, -24,
                        4, -2, 5.6);
        mat3 b = mat3(2, 4.45, -1.45, 
                        -4.3, 23, 4,
                        -9, 0, 12);
        mat3 r = a + b;

        mat3 expect = mat3(3.23, 6.75, -3.45,
                            -3.3, 27.5, -20,
                            -5, -2, 17.6);
        EXPECT_EQ(r, expect);
    }

    TEST(mat3_tests, sub) {
        mat3 a = mat3(1.23, 2.3, -2, 
                        1, 4.5, -24,
                        4, -2, 5.6);
        mat3 b = mat3(2, 4.45, -1.45, 
                        -4.3, 23, 4,
                        -9, 0, 12);
        mat3 r = a - b;

        mat3 expect = mat3(-0.77, -2.15, -0.55,
                            5.3, -18.5, -28,
                            13, -2, -6.4);
        EXPECT_EQ(r, expect);
    }

    TEST(mat3_tests, matrix_mult) {
        mat3 a = mat3(5.12, -16.4, 444,
                        0.68, -23, 4,
                        0.4, 23, 5);
        mat3 b = mat3(90.234, 17.13, 0.11,
                        756, 1, 1,
                        4, 9.3, -2);
        mat3 r = a * b;

        mat3 expect = mat3(-10160.4, 4200.51, -903.837,
                            -17310.6, 25.8484, -30.9252,
                            17444.1, 76.352, 13.044);
        EXPECT_EQ(r, expect);
    }

    TEST(mat3_tests, matrix_vector_mult) {
        mat3 a = mat3(5.12, -16.4, 444,
                        0.68, 2, 9,
                        -2, -9.4, 3);
        vec3 v = vec3(3.4, -76.42, 1);
        vec3 r = a * v;

        vec3 expect = vec3(1714.7, -141.528, 714.548);
        EXPECT_EQ(r, expect);
    }

    TEST(mat3_tests, scalar_mult) {
        mat3 a = mat3(5.12, -16.4, -1.9,
                        0.1, 5, 2,
                        -1, 3.4, -9.4);
        mat3 r = a * -2.2;

        mat3 expect = mat3(-11.264, 36.08, 4.18,
                            -0.22, -11, -4.4,
                            2.2, -7.48, 20.68);
        EXPECT_EQ(r, expect);
    }

    TEST(mat3_tests, scalar_mult_commutative) {
        mat3 a = mat3(5.12, -16.4, -1.9,
                        0.1, 5, 2,
                        -1, 3.4, -9.4);
        mat3 r = -2.2 * a;

        mat3 expect = mat3(-11.264, 36.08, 4.18,
                            -0.22, -11, -4.4,
                            2.2, -7.48, 20.68);
        EXPECT_EQ(r, expect);
    }

    TEST(mat3_tests, scalar_div) {
        mat3 a = mat3(9.99, -19.2, 18.33,
                        -27.96, 4.5, -1.5,
                        24, 3, -3.3);
        mat3 r = a / 3;

        mat3 expect = mat3(3.33, -6.4, 6.11,
                            -9.32, 1.5, -0.5,
                            8, 1, -1.1);
        EXPECT_EQ(r, expect);
    }
}