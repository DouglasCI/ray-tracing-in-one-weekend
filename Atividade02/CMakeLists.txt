cmake_minimum_required(VERSION 3.8)

project(Atividade02)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

include_directories(googletest/include)
include_directories(include)

enable_testing()

add_executable(run_tests
  src/vec2.cpp tests/vec2_tests.cpp
  src/vec3.cpp tests/vec3_tests.cpp
  src/vec4.cpp tests/vec4_tests.cpp
  src/mat2.cpp tests/mat2_tests.cpp
  src/mat3.cpp tests/mat3_tests.cpp
  src/mat4.cpp tests/mat4_tests.cpp
)

find_package(GTest REQUIRED)

target_link_libraries(run_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)