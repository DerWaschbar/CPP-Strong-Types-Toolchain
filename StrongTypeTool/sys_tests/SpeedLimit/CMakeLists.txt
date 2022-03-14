cmake_minimum_required(VERSION 3.21)
project(SpeedLimit)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpeedLimit main.cpp)

add_subdirectory(StrongTypes)
target_link_libraries(SpeedLimit PUBLIC StrongTypes)