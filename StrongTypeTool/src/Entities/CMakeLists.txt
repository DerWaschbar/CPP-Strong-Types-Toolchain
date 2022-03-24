list(APPEND lib_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/BinaryOperation.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/BinaryOperation.h
        ${CMAKE_CURRENT_SOURCE_DIR}/StrongType.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StrongType.h
        ${CMAKE_CURRENT_SOURCE_DIR}/UnaryOperation.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UnaryOperation.h
        ${CMAKE_CURRENT_SOURCE_DIR}/StrongTypeSet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/StrongTypeSet.h)

set(lib_SOURCES "${lib_SOURCES}" PARENT_SCOPE)
