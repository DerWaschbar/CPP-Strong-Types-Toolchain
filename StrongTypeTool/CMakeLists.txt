cmake_minimum_required(VERSION 3.21)
project(StrongTypeTool)

set(CMAKE_CXX_STANDARD 14)

add_executable(StrongTypeToolMain main.cpp)

add_subdirectory(src)
target_link_libraries(StrongTypeToolMain PUBLIC StrongTypeTool)

