list(APPEND lib_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/BinaryAssignmentTypeRule.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/BinaryAssignmentTypeRule.h
        ${CMAKE_CURRENT_SOURCE_DIR}/EmptyFieldsRule.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EmptyFieldsRule.h
        ${CMAKE_CURRENT_SOURCE_DIR}/LiteralsResTypeRule.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/LiteralsResTypeRule.h
        ${CMAKE_CURRENT_SOURCE_DIR}/LiteralsArgTypeRule.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/LiteralsArgTypeRule.h)

set(lib_SOURCES "${lib_SOURCES}" PARENT_SCOPE)