# Libs
add_library(StrongTypeTool
        Generator.cpp
        Generator.h)

add_library(Entities
        Entities/BinaryOperation.cpp
        Entities/BinaryOperation.h
        Entities/StrongType.cpp
        Entities/StrongType.h
        Entities/UnaryOperation.cpp
        Entities/UnaryOperation.h
        Entities/StrongTypeSet.cpp
        Entities/StrongTypeSet.h)

add_library(Deserializer
        Deserializer/YamlDeserializer.cpp
        Deserializer/YamlDeserializer.h)

add_library(Serializer
        Serializer/YamlSerializer.cpp
        Serializer/YamlSerializer.h
        Serializer/CPPHSerializer.cpp
        Serializer/CPPHSerializer.h
        Serializer/CPPSerializer.cpp
        Serializer/CPPSerializer.h
        Serializer/TemplateManager.cpp
        Serializer/TemplateManager.h
        Serializer/CMakeListsSerializer.cpp
        Serializer/CMakeListsSerializer.h
        Serializer/HeaderOnlySerializer.cpp
        Serializer/HeaderOnlySerializer.h)

file(GLOB TEMPLATE_FILES "Serializer/Templates/*")
file(COPY ${TEMPLATE_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Templates/")

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
target_include_directories(StrongTypeTool INTERFACE inja)

find_package(Boost 1.71.0 COMPONENTS filesystem)
target_link_libraries(StrongTypeTool PRIVATE Boost::filesystem)