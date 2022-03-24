cmake_minimum_required(VERSION 3.21)
project(StrongTypeTool)

set(CMAKE_CXX_STANDARD 17)

set(STT_NAME "StrongTypeTool")

add_subdirectory(src)
add_subdirectory(tst)

enable_testing()