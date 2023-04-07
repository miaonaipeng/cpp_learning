cmake_minimum_required(VERSION 3.24)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(cpp_learning src/main.cpp src/basic.cpp src/basic.h)
