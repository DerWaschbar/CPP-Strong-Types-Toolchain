file(GLOB TEMPLATE_FILES "Serializer/Templates/*")
file(COPY ${TEMPLATE_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Templates/")

list(APPEND lib_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/YamlSerializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/YamlSerializer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/CPPHSerializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CPPHSerializer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/CPPSerializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CPPSerializer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/TemplateManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TemplateManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsSerializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CMakeListsSerializer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/HeaderOnlySerializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/HeaderOnlySerializer.h)

set(lib_SOURCES "${lib_SOURCES}" PARENT_SCOPE)
