cmake_minimum_required(VERSION 3.21)
project(StrongTypeTool)

set(CMAKE_CXX_STANDARD 14)

add_executable(StrongTypeTool main.cpp)


# Libs
add_library(Entities
        src/Entities/BinaryOperation.cpp
        src/Entities/BinaryOperation.h
        src/Entities/StrongType.cpp
        src/Entities/StrongType.h
        src/Entities/UnaryOperation.cpp
        src/Entities/UnaryOperation.h)

add_library(Deserializer
        src/Deserializer/YamlDeserializer.cpp
        src/Deserializer/YamlDeserializer.h)

add_library(Serializer
        src/Serializer/YamlSerializer.cpp
        src/Serializer/YamlSerializer.h)


# Links
target_link_libraries(Deserializer PUBLIC Entities)
target_link_libraries(Serializer PUBLIC Entities)

target_link_libraries(StrongTypeTool PUBLIC Entities)
target_link_libraries(StrongTypeTool PUBLIC Deserializer)
target_link_libraries(StrongTypeTool PUBLIC Serializer)


# Dependencies
find_package(yaml-cpp 0.6.0 REQUIRED)
target_link_libraries(StrongTypeTool PRIVATE yaml-cpp)

find_package(inja 3.3.0 REQUIRED)
target_link_libraries(StrongTypeTool INTERFACE inja)