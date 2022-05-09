//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/CPPHSerializer.h"

TEST(CPPHSerializer, serialize_StrongTypeSet1) {
    stt::StrongType T1("TestType", "WT", {}, {});
    stt::StrongTypeSet typeSet({T1}, {});

    CPPHSerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0],
              "//\n"
              "// Created by program.\n"
              "//\n"
              "\n"
              "#ifndef TESTTYPE_H\n"
              "#define TESTTYPE_H\n"
              "\n"
              "\n"
              "class TestType {\n"
              "public:\n"
              "    using wrappedType = WT;\n"
              "\n"
              "    explicit constexpr TestType(wrappedType const& value) : wrappedValue(value) {}\n"
              "    explicit operator wrappedType() const { return  wrappedValue; }\n"
              "\n"
              "    constexpr wrappedType& get() { return wrappedValue; }\n"
              "    constexpr wrappedType get() const { return wrappedValue; }\n"
              "\n"
              "public:\n"
              "\n"
              "private:\n"
              "    wrappedType wrappedValue;\n"
              "};\n"
              "\n"
              "\n"
              "#endif //TESTTYPE_H");
}

TEST(CPPHSerializer, serialize_StrongTypeSet2) {
    stt::StrongType T1("TestType", "int", {stt::BinaryOperation("+", "int", "int")},
                       {stt::UnaryOperation("-", "int")});
    stt::StrongTypeSet typeSet({T1}, {});

    CPPHSerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0],
              "//\n"
              "// Created by program.\n"
              "//\n"
              "\n"
              "#ifndef TESTTYPE_H\n"
              "#define TESTTYPE_H\n"
              "\n"
              "\n"
              "class TestType {\n"
              "public:\n"
              "    using wrappedType = int;\n"
              "\n"
              "    explicit constexpr TestType(wrappedType const& value) : wrappedValue(value) {}\n"
              "    explicit operator wrappedType() const { return  wrappedValue; }\n"
              "\n"
              "    constexpr wrappedType& get() { return wrappedValue; }\n"
              "    constexpr wrappedType get() const { return wrappedValue; }\n"
              "\n"
              "public:\n"
              "\tint operator+(const int &rhs) const;"
              "\n\n"
              "\tint operator-() const;"
              "\n\n"
              "private:\n"
              "    wrappedType wrappedValue;\n"
              "};\n"
              "\n"
              "\n"
              "#endif //TESTTYPE_H");
}

TEST(CPPHSerializer, serialize_Empty) {
    stt::StrongTypeSet typeSet({}, {});

    CPPHSerializer serializer;

    ASSERT_EQ(serializer.serialize(typeSet).size(), 0);
}
