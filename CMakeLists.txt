cmake_minimum_required(VERSION 3.21)
project(rational)

set(CMAKE_CXX_STANDARD 23)

add_executable(rational rational_public_test.cpp rational.h rational.cpp catch.h)
