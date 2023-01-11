cmake_minimum_required(VERSION 3.14)
project(leetcode-cpp)

# Google Test requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  src/contains_duplicate/solution
  src/contains_duplicate/solution.cc
)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(hello_test)

################################################################################

find_package(yaml-cpp REQUIRED)

# add_executable(example example.cpp)

# target_link_libraries(
#   example PRIVATE yaml-cpp
# )

find_package(gflags REQUIRED)
