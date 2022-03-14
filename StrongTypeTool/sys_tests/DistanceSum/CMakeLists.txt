cmake_minimum_required(VERSION 3.21)
project(DistanceSum)

set(CMAKE_CXX_STANDARD 14)

add_executable(DistanceSum main.cpp)

add_subdirectory(StrongTypes)
target_link_libraries(DistanceSum PUBLIC StrongTypes)