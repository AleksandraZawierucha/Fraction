cmake_minimum_required(VERSION 3.10)
project(MasterMind CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

include(cmake/GTest.cmake)

add_executable(fractionTests src/fractionTest.cpp src/fraction.cpp)
target_include_directories(fractionTests PUBLIC include)
target_link_libraries(fractionTests gtest_main gtest)

enable_testing()
add_test(tests fractionTests)
