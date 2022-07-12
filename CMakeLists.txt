cmake_minimum_required(VERSION 3.22)
project(practis C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE _includes "include/*.h" "tool/*.c" "pathfind/*.c")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main main.c ${_includes})
target_link_libraries(main ${CURSES_LIBRARY})

add_executable(Test "unit_test/queue_test.cpp" "include/queue.h" "pathfind/queue.c")
target_link_libraries(Test gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(Test)