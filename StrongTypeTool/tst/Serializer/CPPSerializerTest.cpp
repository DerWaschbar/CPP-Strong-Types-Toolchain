//
// Created by Beka Grdzelishvili (DerWaschbar) on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/CPPSerializer.h"

TEST(CPPSerializer, serialize_StrongTypeSet1) {
    stt::StrongType T1("TestType", "WT", {}, {});
    stt::StrongTypeSet typeSet({T1}, {});

    CPPSerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], "//\n"
                       "// Created by program.\n"
                       "//\n"
                       "\n"
                       "#include \"TestType.h\"\n"
                       "\n");
}

TEST(CPPSerializer, serialize_StrongTypeSet2) {
    stt::StrongType T1("TestType", "int", {stt::BinaryOperation("+", "int", "int")},
                       {stt::UnaryOperation("-", "int")});
    stt::StrongTypeSet typeSet({T1}, {});

    CPPSerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], "//\n"
                       "// Created by program.\n"
                       "//\n"
                       "\n"
                       "#include \"TestType.h\"\n"
                       "\n"
                       "int TestType::operator+(const int &rhs) const {\n"
                       "    return int{ this->wrappedValue + static_cast<wrappedType>(rhs) };\n"
                       "}\n"
                       "\n"
                       "int TestType::operator-() const {\n"
                       "    return int{ -(this->wrappedValue) };\n"
                       "}\n"
                       "\n");
}

TEST(CPPSerializer, serialize_Empty) {
    stt::StrongTypeSet typeSet({}, {});

    CPPSerializer serializer;

    ASSERT_EQ(serializer.serialize(typeSet).size(), 0);
}
