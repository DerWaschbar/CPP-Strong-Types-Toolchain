//
// Created by waschbar on 5/7/22.
//

#include <gtest/gtest.h>

#include "Entities/StrongTypeSet.h"
#include "Serializer/LiteralSerializer.h"

TEST(LiteralSerializer, serialize) {
    stt::StrongType T1("TestType", "WT", {}, {});
    stt::StrongLiteral L1("_tst", "int", "T1");
    stt::StrongTypeSet typeSet({T1}, {L1});

    LiteralSerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], "//\n"
                       "// Created by program.\n"
                       "//\n"
                       "\n"
                       "#include \"StrongLiterals.h\"\n"
                       "\n"
                       "T1 operator\"\"_tst(int value) {\n"
                       "    return T1(value);\n"
                       "}\n"
                       "\n");
}

TEST(LiteralSerializer, serialize_Empty) {
    stt::StrongTypeSet typeSet({}, {});

    LiteralSerializer serializer;

    std::vector<std::string> data = serializer.serialize(typeSet);
    ASSERT_EQ(data.size(), 1);
    ASSERT_EQ(data[0], "//\n"
                       "// Created by program.\n"
                       "//\n"
                       "\n"
                       "#include \"StrongLiterals.h\"\n"
                       "\n");
}


