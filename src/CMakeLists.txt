cmake_minimum_required(VERSION 3.2)
project(LEGO)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES lego.cpp messages.cpp)
add_executable(LEGO ${SOURCE_FILES})
