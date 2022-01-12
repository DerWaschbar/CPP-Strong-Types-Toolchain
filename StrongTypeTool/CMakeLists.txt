cmake_minimum_required(VERSION 3.21)
project(StrongTypeTool)

set(CMAKE_CXX_STANDARD 14)

add_executable(StrongTypeTool main.cpp)

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

target_link_libraries(Deserializer Entities)
target_link_libraries(Serializer Entities)

target_link_libraries(StrongTypeTool Entities)
target_link_libraries(StrongTypeTool Deserializer)
target_link_libraries(StrongTypeTool Serializer)


include_directories("/home/waschbar/Desktop/Thesis/yaml-cpp-yaml-cpp-0.6.0/include")
target_link_libraries(StrongTypeTool "/home/waschbar/Desktop/Thesis/yaml-cpp-yaml-cpp-0.6.0/build/libyaml-cpp.a")
