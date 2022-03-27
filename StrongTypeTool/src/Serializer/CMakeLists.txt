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
        ${CMAKE_CURRENT_SOURCE_DIR}/HeaderOnlySerializer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/LiteralHSerializer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/LiteralHSerializer.h)

set(lib_SOURCES "${lib_SOURCES}" PARENT_SCOPE)
