cmake_minimum_required(VERSION 3.5)
project(xyz)
#set C++11
set(CMAKE_CXX_STANDARD 11)
#enable debugging
add_compile_options(-g)
#use include directory
include_directories(include)
#use source directory
file(GLOB SOURCES "src/*.cpp")
add_executable(xyz ${SOURCES})

