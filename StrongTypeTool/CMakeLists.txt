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
target_link_libraries(Deserializer Entities)
target_link_libraries(Serializer Entities)

target_link_libraries(StrongTypeTool Entities)
target_link_libraries(StrongTypeTool Deserializer)
target_link_libraries(StrongTypeTool Serializer)


# Dependencies
find_package(yaml-cpp 0.6.0 REQUIRED)
target_link_libraries(StrongTypeTool yaml-cpp)

find_package(nlohmann_json 3.2.0 REQUIRED)
target_link_libraries(StrongTypeTool nlohmann_json::nlohmann_json)