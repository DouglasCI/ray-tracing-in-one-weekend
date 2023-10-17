#include <gtest/gtest.h>
#include "../include/vec4.hpp"

namespace {
    TEST(vec4_tests, negative_vector) {
        vec4 v = vec4(1.777, 2, -4.4, 20);
        v = -v;

        vec4 expect = vec4(-1.777, -2, 4.4, -20);
        EXPECT_EQ(v, expect);
    }

    TEST(vec4_tests, compound_add) {
        vec4 v = vec4(1.23, 2.3, -2, 1);
        vec4 u = vec4(2, 4.12345, -1.45, -4.3);
        v += u;

        vec4 expect = vec4(3.23, 6.42345, -3.45, -3.3);
        EXPECT_EQ(v, expect);
    }

    TEST(vec4_tests, compound_mult) {
        vec4 v = vec4(4, 7, 8, 10);
        v *= 3.123;

        vec4 expect = vec4(12.492, 21.861, 24.984, 31.23);
        EXPECT_EQ(v, expect);
    }

    TEST(vec4_tests, compound_div) {
        vec4 v = vec4(4, 3.4, 10.8, -44.6);
        v /= 2;

        vec4 expect = vec4(2, 1.7, 5.4, -22.3);
        EXPECT_EQ(v, expect);
    }

    TEST(vec4_tests, length) {
        vec4 v = vec4(5, -12, 4, 3);

        EXPECT_NEAR(v.length(), 13.9283882772, 0.001);
    }

    TEST(vec4_tests, add) {
        vec4 v = vec4(5.12, 12.1, -7.3, 0);
        vec4 u = vec4(16, 17.13, 9, 3.57);
        vec4 r = v + u;

        vec4 expect = vec4(21.12, 29.23, 1.7, 3.57);
        EXPECT_EQ(r, expect);
    }

    TEST(vec4_tests, sub) {
        vec4 v = vec4(5.12, 256.2, -4.32, 0);
        vec4 u = vec4(16, 17.13, -80, 23.1);
        vec4 r = v - u;

        vec4 expect = vec4(-10.88, 239.07, 75.68, -23.1);
        EXPECT_EQ(r, expect);
    }

    TEST(vec4_tests, elewise_mult) {
        vec4 v = vec4(5.12, -16.4, 444, 0.68);
        vec4 u = vec4(90.234, 17.13, 0.11, 756);
        vec4 r = v * u;

        vec4 expect = vec4(461.99808, -280.932, 48.84, 514.08);
        EXPECT_EQ(r, expect);
    }

    TEST(vec4_tests, scalar_mult) {
        vec4 v = vec4(5.12, -16.4, -1.9, 0.1);
        vec4 r = v * 2.2;

        vec4 expect = vec4(11.264, -36.08, -4.18, 0.22);
        EXPECT_EQ(r, expect);
    }

    TEST(vec4_tests, scalar_mult_commutative) {
        vec4 v = vec4(5.12, -16.4, -1.9, 0.1);
        vec4 r = 2.2 * v;

        vec4 expect = vec4(11.264, -36.08, -4.18, 0.22);
        EXPECT_EQ(r, expect);
    }

    TEST(vec4_tests, scalar_div) {
        vec4 v = vec4(9.99, -19.2, 18.33, -27.96);
        vec4 r = v / 3;

        vec4 expect = vec4(3.33, -6.4, 6.11, -9.32);
        EXPECT_EQ(r, expect);
    }

    TEST(vec4_tests, dot_product) {
        vec4 v = vec4(9.99, -19.2, 4.1, 7.8);
        vec4 u = vec4(2.2, 120, -6, -5.8);

        EXPECT_NEAR(dot(v, u), -2351.86, 0.01);
    }

    TEST(vec4_tests, unit_vector) {
        vec4 v = vec4(8, -5, 3, 1);
        vec4 r = unit_vector(v);

        vec4 expect = vec4(0.80403, -0.502519, 0.301511, 0.100504);
        EXPECT_EQ(r, expect);
    }
}