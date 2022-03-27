cmake_minimum_required(VERSION 3.21)
project(SpeedLimit_Refactored)

set(CMAKE_CXX_STANDARD 14)

add_executable(SpeedLimit_Refactored main.cpp StrongTypes/Speed.cpp StrongTypes/Speed.h StrongTypes/StrongLiterals.cpp StrongTypes/StrongLiterals.h)
