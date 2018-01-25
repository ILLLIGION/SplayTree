cmake_minimum_required(VERSION 2.8.7)
project(SplayTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES include/SplayTree.hpp source/SplayTree.cpp)
set(TEST_FILES_CATCH tests/catch.hpp tests/main.cpp)
set(TEST_FILES_SPLAY_TREE tests/find.cpp tests/insert.cpp tests/remove.cpp)
add_executable(main ${SOURCE_FILES} source/main.cpp)
add_executable(Tests ${SOURCE_FILES} ${TEST_FILES_CATCH} ${TEST_FILES_SPLAY_TREE})
