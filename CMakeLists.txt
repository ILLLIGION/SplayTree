cmake_minimum_required(VERSION 2.8.7)
project(untitled)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -g")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(untitled STATIC ${CMAKE_CURRENT_SOURCE_DIR}/library.cpp)

add_executable(Examples ${CMAKE_CURRENT_SOURCE_DIR} main.cpp)
add_executable(Tests ${TESTS_SOURCE} tests/remove.cpp tests/find.cpp tests/main.cpp tests/insert.cpp) 
