add_executable(StrongTypeToolTest Test.cpp
        Entities/UnaryOperationTest.cpp)

add_test(stt-test StrongTypeToolTest)

target_link_libraries(StrongTypeToolTest PUBLIC StrongTypeTool)

find_package(GTest REQUIRED)
target_link_libraries(StrongTypeToolTest PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})