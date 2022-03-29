list(APPEND lib_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Validator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Validator.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ValidationRule.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ValidationResult.h)

set(lib_SOURCES "${lib_SOURCES}" PARENT_SCOPE)

