cmake_minimum_required(VERSION 2.6)
project(cpp11-tutorial)

add_executable(casts src/casts.cpp)
add_executable(pointers src/pointers.cpp)

install(TARGETS casts pointers RUNTIME DESTINATION bin)
