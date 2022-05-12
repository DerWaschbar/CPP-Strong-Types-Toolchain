#Config
SET(CMAKE_INSTALL_DATADIR "share")
SET(CMAKE_INSTALL_BINDIR "bin")
SET(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/${STT_NAME}")
#SET(BIN_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/${STT_NAME}")

configure_file(Config.in.h Config.h)
include_directories (${CMAKE_BINARY_DIR}/src)

# Exe
add_executable(STGenerator
        StrongTypeToolMain.cpp)

target_link_libraries(STGenerator PUBLIC StrongTypeTool)

# Lib
set(lib_SOURCES)

add_subdirectory(Entities)
add_subdirectory(Deserializer)
add_subdirectory(Serializer)
add_subdirectory(Validation)

add_library(StrongTypeTool STATIC
        "${lib_SOURCES}"
        Generator.cpp
        Generator.h
        GenerationConfig.cpp
        GenerationConfig.h)

# Dependencies
find_package(yaml-cpp 0.6.0 REQUIRED)
target_link_libraries(StrongTypeTool PRIVATE yaml-cpp)

find_package(inja 3.3.0 REQUIRED)
target_include_directories(StrongTypeTool SYSTEM PUBLIC inja)

find_package(Boost 1.71.0 COMPONENTS filesystem program_options)
target_link_libraries(StrongTypeTool PRIVATE Boost::filesystem Boost::program_options)

target_link_libraries(STGenerator PRIVATE Boost::filesystem Boost::program_options)

# Install
file(GLOB TEMPLATE_FILES "Serializer/Templates/*")
file(COPY ${TEMPLATE_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${RESOURCE_PATH}/Templates")

install(FILES ${TEMPLATE_FILES} DESTINATION "${RESOURCE_PATH}/Templates")
install(TARGETS STGenerator DESTINATION "${BIN_PATH}")