cmake_minimum_required(VERSION 2.8.7)
project(SplayTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}<SplayTree.h> /tests/)

add_library(SplayTree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/SplayTree.cpp tests/main.cpp)

add_executable(Examples ${CMAKE_CURRENT_SOURCE_DIR} examples/main.cpp)
add_executable(Tests ${TESTS_SOURCE} tests/insert.cpp tests/find.cpp tests/main.cpp tests/remove.cpp)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include DESTINATION include)

