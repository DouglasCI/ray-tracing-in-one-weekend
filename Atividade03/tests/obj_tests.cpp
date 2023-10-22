/*!
 * \file File for testing the obj class.
 */

#include <gtest/gtest.h>
#include "../include/obj.hpp"
#include "../include/vec2.hpp"
#include "../include/vec3.hpp"

/// @brief Test geometric vertices.
TEST(obj_tests, v_test) {
    ifstream test_file("../tests/mock_inputs/v_test.obj");
    if(!test_file.is_open()) {
        clog << "> Error opening test file!\n";
        exit(1);
    }

    string line, expected_str;
    while(getline(test_file, line)) {
        if(!line.empty())
            expected_str.append(line + "\n");
    }

    obj o = obj("../tests/mock_inputs/v_test.obj");
    string generated_str = o.getGeometricVerticesString();

    EXPECT_TRUE(generated_str == expected_str);
} 

/// @brief Test textures cooordinates.
TEST(obj_tests, vt_test) {
    ifstream test_file("../tests/mock_inputs/vt_test.obj");
    if(!test_file.is_open()) {
        clog << "> Error opening test file!\n";
        exit(1);
    }

    string line, expected_str;
    while(getline(test_file, line)) {
        if(!line.empty())
            expected_str.append(line + "\n");
    }

    obj o = obj("../tests/mock_inputs/vt_test.obj");
    string generated_str = o.getTextureCoordinatesString();

    EXPECT_TRUE(generated_str == expected_str);
} 

/// @brief Test vertex normals.
TEST(obj_tests, vn_test) {
    ifstream test_file("../tests/mock_inputs/vn_test.obj");
    if(!test_file.is_open()) {
        clog << "> Error opening test file!\n";
        exit(1);
    }

    string line, expected_str;
    while(getline(test_file, line)) {
        if(!line.empty())
            expected_str.append(line + "\n");
    }

    obj o = obj("../tests/mock_inputs/vn_test.obj");
    string generated_str = o.getVertexNormalsString();

    EXPECT_TRUE(generated_str == expected_str);
} 

/// @brief Test face elements.
TEST(obj_tests, f_test) {
    ifstream test_file("../tests/mock_inputs/f_test.obj");
    if(!test_file.is_open()) {
        clog << "> Error opening test file!\n";
        exit(1);
    }

    string line, expected_str;
    while(getline(test_file, line)) {
        if(!line.empty())
            expected_str.append(line + "\n");
    }

    obj o = obj("../tests/mock_inputs/f_test.obj");
    string generated_str = o.getFaceElementsString();

    EXPECT_TRUE(generated_str == expected_str);
}

/// @brief Test all components with a real obj file
TEST(obj_tests, full_test) {
    ifstream test_file("../tests/mock_inputs/full_test.obj");
    if(!test_file.is_open()) {
        clog << "> Error opening test file!\n";
        exit(1);
    }

    string line, expected_str;
    while(getline(test_file, line)) {
        if(!line.empty())
            expected_str.append(line + "\n");
    }

    // Build generated obj file
    obj o = obj("../tests/mock_inputs/full_test.obj");
    string generated_str = "mtllib " + o.materialFileName + "\n";
    generated_str.append(o.getGeometricVerticesString());
    generated_str.append(o.getVertexNormalsString());
    generated_str.append(o.getTextureCoordinatesString());
    generated_str.append("g " + o.groupName + "\n");
    generated_str.append("usemtl " + o.materialsNames[0] + "\n");
    generated_str.append(o.getFaceElementsString());

    EXPECT_TRUE(generated_str == expected_str);
}