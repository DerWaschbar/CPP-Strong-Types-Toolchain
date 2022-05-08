cmake_minimum_required(VERSION 3.20)
project(AverageVelocity)

set(CMAKE_CXX_STANDARD 14)

add_executable(AverageVelocity main.cpp)

add_subdirectory(StrongTypes)
target_link_libraries(AverageVelocity PUBLIC StrongTypes)