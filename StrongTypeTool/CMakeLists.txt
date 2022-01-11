cmake_minimum_required(VERSION 3.21)
project(StrongTypeTool)

set(CMAKE_CXX_STANDARD 14)

add_executable(StrongTypeTool main.cpp Parser/Deserializer.cpp Parser/Deserializer.h src/Entities/BinaryOperation.cpp src/Entities/BinaryOperation.h src/Entities/StrongType.cpp src/Entities/StrongType.h src/Deserializer/YamlDeserializer.cpp src/Deserializer/YamlDeserializer.h src/Serializer/CPPSerializer.cpp src/Serializer/CPPSerializer.h)

include_directories("/home/waschbar/Desktop/Thesis/yaml-cpp-yaml-cpp-0.6.0/include")
target_link_libraries(StrongTypeTool "/home/waschbar/Desktop/Thesis/yaml-cpp-yaml-cpp-0.6.0/build/libyaml-cpp.a")
