# Exe
add_executable(STGenerator
        StrongTypeToolMain.cpp)

target_link_libraries(STGenerator PUBLIC StrongTypeTool)


# Lib
set(lib_SOURCES)

add_subdirectory(Entities)
add_subdirectory(Deserializer)
add_subdirectory(Serializer)

add_library(StrongTypeTool STATIC
        "${lib_SOURCES}"
        Generator.cpp
        Generator.h
        Config.cpp
        Config.h)

# Dependencies
find_package(yaml-cpp 0.6.0 REQUIRED)
target_link_libraries(StrongTypeTool PRIVATE yaml-cpp)

find_package(inja 3.3.0 REQUIRED)
target_include_directories(StrongTypeTool INTERFACE inja)

find_package(Boost 1.71.0 COMPONENTS filesystem program_options)
target_link_libraries(StrongTypeTool PRIVATE Boost::filesystem Boost::program_options)

target_link_libraries(STGenerator PRIVATE Boost::filesystem Boost::program_options)