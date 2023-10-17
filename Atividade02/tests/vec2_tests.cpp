#include <gtest/gtest.h>
#include "../include/vec2.hpp"

namespace {
    TEST(vec2_tests, negative_vector) {
        vec2 v = vec2(1.777, 2);
        v = -v;

        vec2 expect = vec2(-1.777, -2);
        EXPECT_EQ(v, expect);
    }

    TEST(vec2_tests, compound_add) {
        vec2 v = vec2(1.23, 2.3);
        vec2 u = vec2(2, 4.12345);
        v += u;

        vec2 expect = vec2(3.23, 6.42345);
        EXPECT_EQ(v, expect);
    }

    TEST(vec2_tests, compound_mult) {
        vec2 v = vec2(4, 7);
        v *= 3.123;

        vec2 expect = vec2(12.492, 21.861);
        EXPECT_EQ(v, expect);
    }

    TEST(vec2_tests, compound_div) {
        vec2 v = vec2(4, 3.4);
        v /= 2;

        vec2 expect = vec2(2, 1.7);
        EXPECT_EQ(v, expect);
    }

    TEST(vec2_tests, length) {
        vec2 v = vec2(5, 12);

        EXPECT_DOUBLE_EQ(v.length(), 13);
    }

    TEST(vec2_tests, add) {
        vec2 v = vec2(5.12, 12.1);
        vec2 u = vec2(16, 17.13);
        vec2 r = v + u;

        vec2 expect = vec2(21.12, 29.23);
        EXPECT_EQ(r, expect);
    }

    TEST(vec2_tests, sub) {
        vec2 v = vec2(5.12, 256.2);
        vec2 u = vec2(16, 17.13);
        vec2 r = v - u;

        vec2 expect = vec2(-10.88, 239.07);
        EXPECT_EQ(r, expect);
    }

    TEST(vec2_tests, elewise_mult) {
        vec2 v = vec2(5.12, -16.4);
        vec2 u = vec2(90.234, 17.13);
        vec2 r = v * u;

        vec2 expect = vec2(461.99808, -280.932);
        EXPECT_EQ(r, expect);
    }

    TEST(vec2_tests, scalar_mult) {
        vec2 v = vec2(5.12, -16.4);
        vec2 r = v * 2.2;

        vec2 expect = vec2(11.264, -36.08);
        EXPECT_EQ(r, expect);
    }

    TEST(vec2_tests, scalar_mult_commutative) {
        vec2 v = vec2(5.12, -16.4);
        vec2 r = 2.2 * v;

        vec2 expect = vec2(11.264, -36.08);
        EXPECT_EQ(r, expect);
    }

    TEST(vec2_tests, scalar_div) {
        vec2 v = vec2(9.99, -19.2);
        vec2 r = v / 3;

        vec2 expect = vec2(3.33, -6.4);
        EXPECT_EQ(r, expect);
    }

    TEST(vec2_tests, dot_product) {
        vec2 v = vec2(9.99, -19.2);
        vec2 u = vec2(2.2, 120);

        EXPECT_DOUBLE_EQ(dot(v, u), -2282.022);
    }

    TEST(vec2_tests, cross_product) {
        vec2 v = vec2(9.99, -19.2);
        vec2 u = vec2(2.2, 120);

        EXPECT_DOUBLE_EQ(cross(v, u), 1241.04);
    }

    TEST(vec2_tests, unit_vector) {
        vec2 v = vec2(3, -4);
        vec2 r = unit_vector(v);

        vec2 expect = vec2(0.6, -0.8);
        EXPECT_EQ(r, expect);
    }
}