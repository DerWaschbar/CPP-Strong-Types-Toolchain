#Config
SET(CMAKE_INSTALL_DATADIR "share")
SET(CMAKE_INSTALL_BINDIR "bin")
SET(RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATADIR}/${STT_NAME}")
SET(BIN_PATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_BINDIR}/${STT_NAME}")

configure_file(../src/Config.in.h ../src/Config.h)
include_directories (${CMAKE_BINARY_DIR}/src)

# Exe
add_executable(StrongTypeToolTest Test.cpp
        Deserializer/YamlDeserializerTest.cpp
        Entities/UnaryOperationTest.cpp
        Entities/BinaryOperationTest.cpp
        Entities/StrongTypeTest.cpp
        Entities/StrongTypeSetTest.cpp
        Entities/StrongLiteralTest.cpp
        Serializer/CMakeListsSerializerTest.cpp
        Serializer/CPPHSerializerTest.cpp
        Serializer/CPPSerializerTest.cpp
        Serializer/HeaderOnlySerializerTest.cpp
        Serializer/LiteralHeaderOnlySerializerTest.cpp
        Serializer/LiteralHSerializer.cpp
        Serializer/LiteralSerializer.cpp
        Serializer/YamlSerializer.cpp
        Validation/ValidationResultTest.cpp
        Validation/Rules/BinaryAssignmentTypeRuleTest.cpp
        Validation/Rules/EmptyFieldsRuleTest.cpp
        Validation/Rules/LiteralsArgTypeRuleTest.cpp
        Validation/Rules/LiteralsResTypeRuleTest.cpp
        Validation/ValidatorTest.cpp)

target_include_directories(StrongTypeToolTest PRIVATE "../src")

# Tests
add_test(stt-test StrongTypeToolTest)

# Links
target_link_libraries(StrongTypeToolTest PUBLIC StrongTypeTool)

# Dependencies
find_package(GTest REQUIRED)
target_link_libraries(StrongTypeToolTest PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
target_include_directories(StrongTypeToolTest SYSTEM PRIVATE ${GTEST_INCLUDE_DIR})
