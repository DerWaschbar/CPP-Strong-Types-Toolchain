add_executable(StrongTypeToolTest Test.cpp
        Entities/UnaryOperationTest.cpp)

# Tests
add_test(stt-test StrongTypeToolTest)

# Links
target_link_libraries(StrongTypeToolTest PUBLIC StrongTypeTool)

# Dependencies
find_package(GTest REQUIRED)
target_link_libraries(StrongTypeToolTest PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})