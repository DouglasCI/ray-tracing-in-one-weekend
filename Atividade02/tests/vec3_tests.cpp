#include <gtest/gtest.h>
#include "../include/vec3.hpp"

namespace {
    TEST(vec3_tests, negative_vector) {
        vec3 v = vec3(1.777, 2, -4.4);
        v = -v;

        vec3 expect = vec3(-1.777, -2, 4.4);
        EXPECT_EQ(v, expect);
    }

    TEST(vec3_tests, compound_add) {
        vec3 v = vec3(1.23, 2.3, -2);
        vec3 u = vec3(2, 4.12345, -1.45);
        v += u;

        vec3 expect = vec3(3.23, 6.42345, -3.45);
        EXPECT_EQ(v, expect);
    }

    TEST(vec3_tests, compound_mult) {
        vec3 v = vec3(4, 7, 8);
        v *= 3.123;

        vec3 expect = vec3(12.492, 21.861, 24.984);
        EXPECT_EQ(v, expect);
    }

    TEST(vec3_tests, compound_div) {
        vec3 v = vec3(4, 3.4, 10.8);
        v /= 2;

        vec3 expect = vec3(2, 1.7, 5.4);
        EXPECT_EQ(v, expect);
    }

    TEST(vec3_tests, length) {
        vec3 v = vec3(5, 12, 0);

        EXPECT_DOUBLE_EQ(v.length(), 13);
    }

    TEST(vec3_tests, add) {
        vec3 v = vec3(5.12, 12.1, -7.3);
        vec3 u = vec3(16, 17.13, 9);
        vec3 r = v + u;

        vec3 expect = vec3(21.12, 29.23, 1.7);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, sub) {
        vec3 v = vec3(5.12, 256.2, -4.32);
        vec3 u = vec3(16, 17.13, -80);
        vec3 r = v - u;

        vec3 expect = vec3(-10.88, 239.07, 75.68);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, elewise_mult) {
        vec3 v = vec3(5.12, -16.4, 444);
        vec3 u = vec3(90.234, 17.13, 0.11);
        vec3 r = v * u;

        vec3 expect = vec3(461.99808, -280.932, 48.84);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, scalar_mult) {
        vec3 v = vec3(5.12, -16.4, -1.9);
        vec3 r = v * 2.2;

        vec3 expect = vec3(11.264, -36.08, -4.18);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, scalar_mult_commutative) {
        vec3 v = vec3(5.12, -16.4, -1.9);
        vec3 r = 2.2 * v;

        vec3 expect = vec3(11.264, -36.08, -4.18);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, scalar_div) {
        vec3 v = vec3(9.99, -19.2, 18.33);
        vec3 r = v / 3;

        vec3 expect = vec3(3.33, -6.4, 6.11);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, dot_product) {
        vec3 v = vec3(9.99, -19.2, 4.1);
        vec3 u = vec3(2.2, 120, -6);

        EXPECT_NEAR(dot(v, u), -2306.62, 0.01);
    }

    TEST(vec3_tests, cross_product) {
        vec3 v = vec3(9.99, -19.2, 4.1);
        vec3 u = vec3(2.2, 120, -6);
        vec3 r = cross(v, u);

        vec3 expect = vec3(-376.8, 68.96, 1241.04);
        EXPECT_EQ(r, expect);
    }

    TEST(vec3_tests, unit_vector) {
        vec3 v = vec3(3, -4, 0);
        vec3 r = unit_vector(v);

        vec3 expect = vec3(0.6, -0.8, 0);
        EXPECT_EQ(r, expect);
    }
}