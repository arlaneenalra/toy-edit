cmake_minimum_required(VERSION 3.31)
project(toy-edit VERSION 0.0.1)

set(UPDATE_TYPE git)

set(CMAKE_CXX_STANDARD 20)

include(CTest)

add_subdirectory(src)

add_subdirectory(test)

ENABLE_TESTING()