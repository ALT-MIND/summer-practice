cmake_minimum_required(VERSION 3.22)
project(practis C)

set(CMAKE_C_STANDARD 99)
file(GLOB_RECURSE _includes "include/*.h" "tool/*.c" "pathfind/*.c")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(main main.c ${_includes})
target_link_libraries(main ${CURSES_LIBRARY})
