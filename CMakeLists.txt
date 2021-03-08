cmake_minimum_required(VERSION 3.19)
project("TestPyBind11")

# CMAKE_MINIMUM_REQUIRED_VERSION(VERSION 2.8)

set(CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_part_libs/pybind11)

pybind11_add_module(first_test src/wrappers.cpp src/public/Matrix.h src/private/Matrix.cpp)

add_executable(test src/app.cpp src/public/Matrix.h src/private/Matrix.cpp) 